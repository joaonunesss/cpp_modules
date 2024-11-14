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

void	FordJohnsonSelector(char **av, int ac)
{
	std::clock_t start;
	std::clock_t end;
	double elapsed_time;

	//-----------------------------------------VECTOR----------------------------------------------------//
	start = std::clock();
	PmergeMe<std::vector<double>, std::vector<std::pair<double, double> > > vector;
	std::vector<double> printVec = vector.FordJohnson(av, ac);
	end = std::clock();

	std::cout << "Vector After:" << std::endl;
	for (std::vector<double>::iterator it = printVec.begin(); it != printVec.end(); it++)
			std::cout << *it << " ";
	std::cout << std::endl;
	
	elapsed_time = double(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Time to process a range of " << printVec.size() << " elements with std::vector<double>: " << elapsed_time << " microseconds (µs)" << std::endl << std::endl;

	//-----------------------------------------DEQUE------------------------------------------------------//
	start = std::clock();
	PmergeMe<std::deque<double>, std::deque<std::pair<double, double> > > deque;
	std::deque<double> printDeq = deque.FordJohnson(av, ac);
	end = std::clock();

	std::cout << "Deque After:" << std::endl;
	for (std::deque<double>::iterator it = printDeq.begin(); it != printDeq.end(); it++)
			std::cout << *it << " ";
	std::cout << std::endl;
	
	elapsed_time = double(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Time to process a range of " << printDeq.size() << " elements with std::deque<double>: " << elapsed_time << " microseconds (µs)" << std::endl;
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
	if (i == 2)
	{
		std::cerr << "Error. Empty or single-element vector, no sorting needed." << std::endl;
		return EXIT_FAILURE;
	}

	i = 1;
	std::cout << "Sequence Before:" << std::endl;
	while(av[i])
		std::cout << av[i++] << " ";
	std::cout << std::endl << std::endl;

	FordJohnsonSelector(av, ac);
	
	return EXIT_SUCCESS;
}