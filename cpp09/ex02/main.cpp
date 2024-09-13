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

int main (int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Invalid number of args!" << std::endl;
		return EXIT_FAILURE;
	}

	PmergeMe pm;
	std::vector<int>	vector;
	std::list<int> 		list;

	for (int i = 1; i < ac; i++)
	{
		if (std::string(av[i]).find_first_not_of("0123456789 ") != std::string::npos)
		{
			std::cerr << "Error. Invalid characters detected." << std::endl;
			return EXIT_FAILURE;
		}
		vector.push_back(std::atoi(av[i]));
		list.push_back(std::atoi(av[i]));
	}
		
	if (vector.size() <= 1 || list.size() <= 1)
	{
		std::cerr << "Error. Empty or single-element vector, no sorting needed." << std::endl;
		return EXIT_FAILURE;
	}
	
	pm.VectorFordJohnson(vector);
	std::cout << std::endl;
	pm.ListFordJohnson(list);

}