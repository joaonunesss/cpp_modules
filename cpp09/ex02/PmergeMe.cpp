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

bool	PmergeMe::FordJohnsonSelector(char **av, int ac)
{
	std::vector<int>	vector;
	std::list<int> 		list;

	PmergeMe PmergeMe;
	
	if (PmergeMe.vectorFordJohnson(av, ac))
		return EXIT_FAILURE;
	std::cout << std::endl;
	/* if (PmergeMe.ListFordJohnson(av, ac))
		return EXIT_FAILURE; */
	return EXIT_SUCCESS;
}

void printPairs(std::vector<std::pair<int, int> > &vector)
{
	for (std::vector<std::pair<int, int> >::iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
	std::cout << std::endl;
}

void printVec(std::vector<int> &vector)
{
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void createPairs(std::vector<int> &vector, std::vector<std::pair<int, int> > &pairs)
{
	bool odd_flag = false;
	int struggler;

	if (vector.size() % 2 != 0)
	{
		struggler = vector.back();
		vector.pop_back();
		odd_flag = true;
	}

	/* Divide o vector por pares */
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it += 2)
	{
		if (*it > *(it + 1))
			pairs.push_back(std::make_pair(*it, *(it + 1)));
		else
			pairs.push_back(std::make_pair(*(it + 1), *it));
	}
	if (odd_flag)
		pairs.push_back(std::make_pair(struggler, -1));
}

bool	PmergeMe::vectorFordJohnson(char **av, int ac)
{
	std::clock_t start = std::clock();

	std::vector<int> vector;
	std::vector<std::pair<int, int> > pairs;
	
	for (int i = 1; i < ac; i++)
		vector.push_back(std::atoi(av[i]));
	
	createPairs(vector, pairs);
	recursiveDivide(pairs);

 	/* No vector com  os numeros maiores ja organizados e coloca os menores por ordem dos pares*/
	vector.clear();
	for (size_t i = 0 ; i < pairs.size(); i++)
		vector.push_back(pairs[i].first);
 
	insertionSort(vector, pairs);
	
	std::clock_t end = std::clock();

	std::cout << "Vector After:" << std::endl;
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
			std::cout << *it << " ";
	std::cout << std::endl;
	
	double elapsed_time = double(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << vector.size() << " elements with std::vector<int>: " << elapsed_time << " microseconds (µs)" << std::endl;
	
	return EXIT_SUCCESS;
}

void PmergeMe::recursiveDivide(std::vector<std::pair<int , int> > &pairs)
{
	int mid = pairs.size() / 2;

	std::vector<std::pair<int , int> > left(pairs.begin(), pairs.begin() + mid);
	std::vector<std::pair<int , int> > right(pairs.begin() + mid, pairs.end());

	if (pairs.size() == 1)
		return ;

	recursiveDivide(left);
	recursiveDivide(right);
	mergeVectors(left, right, pairs);
}

void PmergeMe::mergeVectors(std::vector<std::pair<int , int> > &left, std::vector<std::pair<int , int> > &right, std::vector<std::pair<int , int> > &result)
{
	/* Organiza o vector de pares por ordem crescente da primeira seq de numeros do vector */
	result.clear();
	while (!left.empty() && !right.empty())
	{
		if (left[0].first < right[0].first || right[0].second == -1)
		{
			result.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}	
	while (!left.empty())
	{
		result.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty())
	{
		result.push_back(right.front());
		right.erase(right.begin());
	}
}

void binarySearch(std::vector<int> &vector, int number)
{
	int start, middle, end;

	start = 0;
	end = vector.size() - 1;
	while (start <= end)
	{
		middle = start + (end - start) / 2;
		if (number >= vector[middle])
			start = middle + 1;
		else if (number < vector[middle])		
			end = middle - 1;
	}
	vector.insert(vector.begin() + start, number);
}

void PmergeMe::insertionSort(std::vector<int> &vector, std::vector<std::pair<int, int> > &pairs)
{
	std::vector<int> jacob;

	/* Generate JacobSthal Sequence */
	if (pairs.empty())
		jacob.push_back(0);
	else if (pairs.size() == 1)
	{
		jacob.push_back(0);
		jacob.push_back(1);
	}
	else
	{
		jacob.push_back(0);
		jacob.push_back(1);

		for (size_t i = 2; (size_t)(jacob[i - 1] + 2 * jacob[i - 2]) < (2 *pairs.size()); i++)//O numero de Jacob nao pode ser maior que o tamanho original da sequencia
			jacob.push_back(jacob[i - 1] + (2 * jacob[i - 2]));
	}

	/* Binary Search */
	if (!pairs.empty())
		binarySearch(vector, pairs[0].second); //No primeiro par o Menor e pode-se colocar logo no inicio do vector

	/*std::cout << "Jacob: " << std::endl;
	printVec(jacob);
	std::cout << "Pairs: " << std::endl;
	printPairs(pairs);
	std::cout << "Vector0: " << std::endl;
	printVec(vector); */
	
	for (size_t i = 1; i < jacob.size(); i++)
    {
        for (int j = jacob[i]; j > jacob[i - 1]; j--)
        {
            if (j >= (int)pairs.size())
                continue; // Ensure we do not go out of bounds

            binarySearch(vector, pairs[j].second);

            // Stop if vector size matches pairs size, indicating all elements are inserted
            if ((int)vector.size() == (2 * (int)pairs.size()))
                return;
        }
    }
/* 	std::cout << "Final: " << std::endl;
	printVec(vector); */
}

/* A sequencia de Jacob e utilizada para calcular a posicao de determinado numero numa sequencia */
/*
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

void	PmergeMe::vectorFordJohnson(std::vector<int> vector)
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
} */