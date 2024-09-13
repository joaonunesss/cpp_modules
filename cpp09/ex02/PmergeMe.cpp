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
 
std::vector<int>	PmergeMe::mergeVectors(std::vector<int> left, std::vector<int> right)
{
	std::vector<int> merged;

	while (!left.empty() && !right.empty())
	{
		if (left.front() <= right.front())
		{
			merged.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			merged.push_back(right.front());
			right.erase(right.begin());
		}
	}
	while (!left.empty())//if left vector is odd-sized
	{
		merged.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty())//if right vector is odd-sized
	{
		merged.push_back(right.front());
		right.erase(right.begin());
	}

	return merged;
}

std::vector<int>	PmergeMe::divideVectors(std::vector<int> vector)
{
	int mid = vector.size() / 2;

	if (vector.size() <= 1)
		return vector;
	
	std::vector<int> left(vector.begin(), vector.begin() + mid);
	std::vector<int> right(vector.begin() + mid, vector.end());

	left = divideVectors(left);
	right = divideVectors(right);
	
	return mergeVectors(left, right);
}

void				PmergeMe::VectorFordJohnson(std::vector<int> vector)
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

std::list<int>		PmergeMe::mergeLists(std::list<int> left, std::list<int> right)
{
	std::list<int> merged;

	while (!left.empty() && !right.empty())
	{
		if (left.front() <= right.front())
		{
			merged.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			merged.push_back(right.front());
			right.erase(right.begin());
		}
	}
	while (!left.empty())//if left list is odd-sized
	{
		merged.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty())//if right list is odd-sized
	{
		merged.push_back(right.front());
		right.erase(right.begin());
	}

	return merged;
}

std::list<int>		PmergeMe::divideLists(std::list<int> list)
{
	int mid = list.size() / 2;

	if (list.size() <= 1)
		return list;

	std::list<int> left, right;
	
	for (int i = 0; i < mid; i++)
	{
		left.push_back(list.front());
		list.pop_front();
	}
	right = list;

	left = divideLists(left);
	right = divideLists(right);
	
	return mergeLists(left, right);
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
