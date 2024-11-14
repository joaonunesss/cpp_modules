/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:56:24 by jmarinho          #+#    #+#             */
/*   Updated: 2024/09/13 14:47:03 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>
#include <cmath>

template <typename T, typename U>
class PmergeMe {
	
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &other);
		
		T			FordJohnson(char **av, int ac);

	private:
		void		createPairs(T &container, U &pairs);
		void		recursiveDivide(U &pairs);
		void		mergeContainers(U &left, U &right, U &result);
		void		insertionSort(T &container, U &pairs);
		void		binarySearch(T &container, int number);
		void 		printPairs(U &pairs);
		void		printContainer(T &container);
};

template <typename T, typename U>
PmergeMe<T, U>::PmergeMe() {}

template <typename T, typename U>
PmergeMe<T, U>::~PmergeMe() {}

template <typename T, typename U>
PmergeMe<T, U>::PmergeMe(const PmergeMe &other) {
	*this = other;
}

template <typename T, typename U>
PmergeMe<T, U> &PmergeMe<T, U>::operator=(const PmergeMe &other) {
	(void) other;
	return *this;
}

template <typename T, typename U>
T	PmergeMe<T, U>::FordJohnson(char **av, int ac)
{
	T container;
	U pairs;
	
	for (int i = 1; i < ac; i++)
		container.push_back(std::atoi(av[i]));
	
	createPairs(container, pairs);
	recursiveDivide(pairs);

	container.clear();
	for (size_t i = 0 ; i < pairs.size(); i++)
	{
		if (pairs[i].first == -1)
			continue;
		container.push_back(pairs[i].first);
	}
 
	insertionSort(container, pairs);

	return container;
}

template <typename T, typename U>
void	PmergeMe<T, U>::createPairs(T &container, U &pairs)
{
	bool odd_flag = false;
	int struggler;

	if (container.size() % 2 != 0)
	{
		struggler = container.back();
		container.pop_back();
		odd_flag = true;
	}

	for (typename T::iterator it = container.begin(); it != container.end(); it += 2)
	{
		if (*it > *(it + 1))
			pairs.push_back(std::make_pair(*it, *(it + 1)));
		else
			pairs.push_back(std::make_pair(*(it + 1), *it));
	}
	if (odd_flag)
		pairs.push_back(std::make_pair(-1, struggler));
}

template <typename T, typename U>
void	PmergeMe<T, U>::recursiveDivide(U &pairs)
{
	int mid = pairs.size() / 2;

	U left(pairs.begin(), pairs.begin() + mid);
	U right(pairs.begin() + mid, pairs.end());

	if (pairs.size() == 1)
		return ;

	recursiveDivide(left);
	recursiveDivide(right);
	mergeContainers(left, right, pairs);
} 

template <typename T, typename U>
void	PmergeMe<T, U>::mergeContainers(U &left, U &right, U &result)
{
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

template <typename T, typename U>
void	PmergeMe<T, U>::binarySearch(T &container, int number)
{
	int start, middle, end;

	start = 0;
	end = container.size() - 1;
	while (start <= end)
	{
		middle = start + (end - start) / 2;
		if (number >= container[middle])
			start = middle + 1;
		else if (number < container[middle])		
			end = middle - 1;
	}
	container.insert(container.begin() + start, number);
} 

template <typename T, typename U>
void PmergeMe<T, U>::insertionSort(T &container, U &pairs)
{
	T jacob;

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
		binarySearch(container, pairs[0].second); //No primeiro par o Menor e pode-se colocar logo no inicio do vector
	
	for (size_t i = 1; i < jacob.size(); i++)
    {
        for (int j = jacob[i]; j > jacob[i - 1]; j--)
        {
            if (j >= (int)pairs.size())
                continue; // Ensure we do not go out of bounds

            binarySearch(container, pairs[j].second);

            // Stop if container size matches pairs size, indicating all elements are inserted
            if ((int)container.size() == (2 * (int)pairs.size()))
                return;
        }
    }

}

template <typename T, typename U>
void PmergeMe<T, U>::printPairs(U &container)
{
	for (typename U::iterator it = container.begin(); it != container.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
	std::cout << std::endl;
}

template <typename T, typename U>
void PmergeMe<T, U>::printContainer(T &container)
{
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

#endif