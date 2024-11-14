/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:46:08 by jmarinho          #+#    #+#             */
/*   Updated: 2024/09/13 14:34:27 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//https://github.com/nerraou/Ford-Johnson-algorithm?tab=readme-ov-file

bool	FordJohnsonSelector(char **av, int ac)
{

	std::clock_t start;
	std::clock_t end;
	double elapsed_time;

	start = std::clock();
	PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > > vector;
	std::vector<int> printVec = vector.FordJohnson(av, ac);

	if (printVec.empty())
		return EXIT_FAILURE;
	else
	{
		end = std::clock();
		std::cout << "Vector After:" << std::endl;
		for (std::vector<int>::iterator it = printVec.begin(); it != printVec.end(); it++)
				std::cout << *it << " ";
		std::cout << std::endl;
		
		elapsed_time = double(end - start) / CLOCKS_PER_SEC * 1000000;

		std::cout << "Time to process a range of " << printVec.size() << " elements with std::vector<int>: " << elapsed_time << " microseconds (µs)" << std::endl;
	}

	start = std::clock();
	PmergeMe<std::deque<int>, std::deque<std::pair<int, int> > > deque;
	std::deque<int> printDeq = deque.FordJohnson(av, ac);

	if (printDeq.empty())
		return EXIT_FAILURE;
	else
	{
		end = std::clock();
		std::cout << "Deque After:" << std::endl;
		for (std::deque<int>::iterator it = printDeq.begin(); it != printDeq.end(); it++)
				std::cout << *it << " ";
		std::cout << std::endl;
		
		elapsed_time = double(end - start) / CLOCKS_PER_SEC * 1000000;

		std::cout << "Time to process a range of " << printDeq.size() << " elements with std::deque<int>: " << elapsed_time << " microseconds (µs)" << std::endl;
	}
	return EXIT_SUCCESS;
}

int main (int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Invalid number of args!" << std::endl;
		return EXIT_FAILURE;
	}
	for (int i = 1; i < ac; i++)
	{
		if (std::string(av[i]).find_first_not_of("0123456789 ") != std::string::npos)
		{
			std::cerr << "Error. Invalid characters detected." << std::endl;
			return EXIT_FAILURE;
		}
	}
	int i = 1;
	while(av[i])
		i++;
	if (i == 1 || i == 2)
	{
		std::cerr << "Error. Empty or single-element vector, no sorting needed." << std::endl;
		return EXIT_FAILURE;
	}

	i = 1;
	std::cout << "Sequence Before:" << std::endl;
	while(av[i])
		std::cout << av[i++] << " ";
	std::cout << std::endl;

	FordJohnsonSelector(av, ac);
	
	return EXIT_SUCCESS;
}