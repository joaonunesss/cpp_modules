/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:56:27 by jmarinho          #+#    #+#             */
/*   Updated: 2024/09/13 15:32:01 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	(void) other;
	return *this;
}

/* A sequencia de Jacob e utilizada para calcular a posicao de determinado numero numa sequencia*/
std::vector<int> PmergeMe::jacobSequence(int size)
{
	std::vector<int> jacob;
	std::vector<int> final_seq;
	int curr = 3;
	int n = 3;

	jacob.push_back(1);

	while (jacob.back() < size)
	{
		jacob.push_back(curr);
		curr = std::pow(2, n) - curr;
		n++;
	}
	final_seq.push_back(1);
	for (int i = 1; i < (int)jacob.size(); i++)
	{
		for (int j = jacob[i]; j > jacob[i - 1]; j--)
		{
			if (j <= size)
				final_seq.push_back(j);
		}
	}

	return (final_seq);
}

std::vector<int>	PmergeMe::divideVectors(std::vector<int> vector)
{
	std::vector<int> larger;
	std::vector<int> smaller;

	bool odd_flag = false;
	int struggler;


	if (vector.size() <= 1)
		return vector;
	if (vector.size() % 2 != 0)
	{
		struggler = vector.back();
		vector.pop_back();
		odd_flag = true;
	}
	
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it += 2)
	{
		if (*it < *(it + 1))
		{
			smaller.push_back(*it);
			larger.push_back(*(it + 1));
		}
		else
		{
			smaller.push_back(*(it + 1));
			larger.push_back(*it);
		}
	}
	if (odd_flag)
		smaller.push_back(struggler);

	larger = divideVectors(larger);
	std::vector<int> jacob = jacobSequence(smaller.size());

	for (std::vector<int>::iterator it = jacob.begin(); it != jacob.end(); it++)
	{
		std::vector<int>::iterator lower = std::lower_bound(larger.begin(), larger.end(), smaller.at(*it - 1));
		larger.insert(lower, smaller.at(*it - 1));
	}

	return larger;
}

void	PmergeMe::VectorFordJohnson(std::vector<int> vector)
{
	if (vector.size() < 15 )
	{
		std::cout << "Vector Before: ";
		for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Vector Before: ";
		std::vector<int>::iterator it = vector.begin();
		for (int i = 0; i < 5; i++)
			std::cout << *it++ << " ";
		std::cout << "[...]" << std::endl;
	}
	
	std::clock_t start = std::clock();
	
	vector = divideVectors(vector);
	
	std::clock_t end = std::clock();
	
	if (vector.size() < 15 )
	{
		std::cout << "Vector After: ";
		for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Vector After: ";
		std::vector<int>::iterator it = vector.begin();
		for (int i = 0; i < 5; i++)
			std::cout << *it++ << " ";
		std::cout << "[...]" << std::endl;
	}
	
	double elapsed_time = double(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << vector.size() << " elements with std::vector<int>: " << std::fixed << std::setprecision(2) << elapsed_time << " microseconds (µs)" << std::endl;
}

std::list<int>		PmergeMe::divideLists(std::list<int> list)
{
	std::list<int> larger;
	std::list<int> smaller;

	bool odd_flag = false;
	int struggler;


	if (list.size() <= 1)
		return list;
	if (list.size() % 2 != 0)
	{
		struggler = list.back();
		list.pop_back();
		odd_flag = true;
	}
	
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		std::list<int>::iterator curr = it;
		if (*it < *(++it))
		{
			smaller.push_back(*it);
			larger.push_back(*curr);
		}
		else
		{
			smaller.push_back(*curr);
			larger.push_back(*it);
		}
	}
	if (odd_flag)
		smaller.push_back(struggler);

	larger = divideLists(larger);
	std::vector<int> jacob = jacobSequence(smaller.size());

	for (std::vector<int>::iterator it = jacob.begin(); it != jacob.end(); it++)
	{
		std::list<int>::iterator index = smaller.begin();
		std::advance(index, *it - 1);//std::list does not support random access, so we need to iterate to the desired index
		std::list<int>::iterator lower = std::lower_bound(larger.begin(), larger.end(), *index);
	
		larger.insert(lower, *index);
	}

	return larger;
}

void				PmergeMe::ListFordJohnson(std::list<int> list)
{

	if (list.size() < 15 )
	{
		std::cout << "List Before: ";
		for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "List Before: ";
		std::list<int>::iterator it = list.begin();
		for (int i = 0; i < 5; i++)
			std::cout << *it++ << " ";
		std::cout << "[...]" << std::endl;
	}
	
	std::clock_t start = std::clock();
	
	list = divideLists(list);
	
	std::clock_t end = std::clock();
	
	if (list.size() < 15 )
	{
		std::cout << "List After: ";
		for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "List After 	: ";
		std::list<int>::iterator it = list.begin();
		for (int i = 0; i < 5; i++)
			std::cout << *it++ << " ";
		std::cout << "[...]" << std::endl;
	}

	double elapsed_time = double(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << list.size() << " elements with std::list<int>: " << std::fixed << std::setprecision(2) << elapsed_time << " microseconds (µs)" << std::endl;
}
