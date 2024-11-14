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
	PmergeMe PmergeMe;
	
	if (PmergeMe.vectorFordJohnson(av, ac))
		return EXIT_FAILURE;
	std::cout << std::endl;
	if (PmergeMe.dequeFordJohnson(av, ac))
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

//------------------------ALGO FOR VECTOR---------------------------------//

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

void PmergeMe::createPairsForVectors(std::vector<int> &vector, std::vector<std::pair<int, int> > &pairs)
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
	
	createPairsForVectors(vector, pairs);
	recursiveDivideVectors(pairs);

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

void PmergeMe::recursiveDivideVectors(std::vector<std::pair<int , int> > &pairs)
{
	int mid = pairs.size() / 2;

	std::vector<std::pair<int , int> > left(pairs.begin(), pairs.begin() + mid);
	std::vector<std::pair<int , int> > right(pairs.begin() + mid, pairs.end());

	if (pairs.size() == 1)
		return ;

	recursiveDivideVectors(left);
	recursiveDivideVectors(right);
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

void PmergeMe::binarySearchForVectors(std::vector<int> &vector, int number)
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
		binarySearchForVectors(vector, pairs[0].second); //No primeiro par o Menor e pode-se colocar logo no inicio do vector

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

            binarySearchForVectors(vector, pairs[j].second);

            // Stop if vector size matches pairs size, indicating all elements are inserted
            if ((int)vector.size() == (2 * (int)pairs.size()))
                return;
        }
    }
/* 	std::cout << "Final: " << std::endl;
	printVec(vector); */
}

//------------------------ALGO FOR DEQUE---------------------------------//

void printPairs(std::deque<std::pair<int, int> > &deque)
{
	for (std::deque<std::pair<int, int> >::iterator it = deque.begin(); it != deque.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
	std::cout << std::endl;
}

void printDeq(std::deque<int> &deque)
{
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void		PmergeMe::createPairsForDeques(std::deque<int> &deque, std::deque<std::pair<int, int> > &pairs)
{
	bool odd_flag = false;
	int struggler;

	if (deque.size() % 2 != 0)
	{
		struggler = deque.back();
		deque.pop_back();
		odd_flag = true;
	}

	/* Divide o deque por pares */
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it += 2)
	{
		if (*it > *(it + 1))
			pairs.push_back(std::make_pair(*it, *(it + 1)));
		else
			pairs.push_back(std::make_pair(*(it + 1), *it));
	}
	if (odd_flag)
		pairs.push_back(std::make_pair(struggler, -1));
}


bool		PmergeMe::dequeFordJohnson(char **av, int ac)
{
	std::clock_t start = std::clock();

	std::deque<int> deque;
	std::deque<std::pair<int, int> > pairs;
	
	for (int i = 1; i < ac; i++)
		deque.push_back(std::atoi(av[i]));
	
	createPairsForDeques(deque, pairs);
	recursiveDivideForDeque(pairs);

 	/* No deque com  os numeros maiores ja organizados e coloca os menores por ordem dos pares*/
	deque.clear();
	for (size_t i = 0 ; i < pairs.size(); i++)
		deque.push_back(pairs[i].first);
 
	insertionSortForDeques(deque, pairs);
	
	std::clock_t end = std::clock();

	std::cout << "Deque After:" << std::endl;
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
			std::cout << *it << " ";
	std::cout << std::endl;
	
	double elapsed_time = double(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << deque.size() << " elements with std::deque<int>: " << elapsed_time << " microseconds (µs)" << std::endl;
	
	return EXIT_SUCCESS;
}

void		PmergeMe::recursiveDivideForDeque(std::deque<std::pair<int, int> > &pairs)
{
    	int mid = pairs.size() / 2;

	std::deque<std::pair<int , int> > left(pairs.begin(), pairs.begin() + mid);
	std::deque<std::pair<int , int> > right(pairs.begin() + mid, pairs.end());

	if (pairs.size() == 1)
		return ;

	recursiveDivideForDeque(left);
	recursiveDivideForDeque(right);
	mergeDeques(left, right, pairs);
}

void		PmergeMe::mergeDeques(std::deque<std::pair<int , int> > &left, std::deque<std::pair<int , int> > &right, std::deque<std::pair<int , int> > &result)
{
    	/* Organiza o deque de pares por ordem crescente da primeira seq de numeros do deque */
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

void		PmergeMe::binarySearchForDeques(std::deque<int> &deque, int number)
{
	int start, middle, end;

	start = 0;
	end = deque.size() - 1;
	while (start <= end)
	{
		middle = start + (end - start) / 2;
		if (number >= deque[middle])
			start = middle + 1;
		else if (number < deque[middle])		
			end = middle - 1;
	}
	deque.insert(deque.begin() + start, number);
}

void		PmergeMe::insertionSortForDeques(std::deque<int> &deque, std::deque<std::pair<int, int> > &pairs)
{
    	std::deque<int> jacob;

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
		binarySearchForDeques(deque, pairs[0].second); //No primeiro par o Menor e pode-se colocar logo no inicio do deque

	/*std::cout << "Jacob: " << std::endl;
	printVec(jacob);
	std::cout << "Pairs: " << std::endl;
	printPairs(pairs);
	std::cout << "deque0: " << std::endl;
	printVec(deque); */
	
	for (size_t i = 1; i < jacob.size(); i++)
    {
        for (int j = jacob[i]; j > jacob[i - 1]; j--)
        {
            if (j >= (int)pairs.size())
                continue; // Ensure we do not go out of bounds

            binarySearchForDeques(deque, pairs[j].second);

            // Stop if deque size matches pairs size, indicating all elements are inserted
            if ((int)deque.size() == (2 * (int)pairs.size()))
                return;
        }
    }
/* 	std::cout << "Final: " << std::endl;
	printVec(deque); */
}
