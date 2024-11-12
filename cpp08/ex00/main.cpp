/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:12:42 by jmarinho          #+#    #+#             */
/*   Updated: 2024/08/12 17:33:21 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[36m"
# define RESET "\033[37m"

int main()
{
	std::vector<int> numbers;
	numbers.push_back(0);
	numbers.push_back(1);
	numbers.push_back(5);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(2);

	int nbr_to_find = 2;
	int wrong_nbr_to_find = 10;

	//Will find
	std::cout << BLUE;
	try {
		
		std::vector<int>::iterator result = easyfind(numbers, nbr_to_find);
		if (result != numbers.end())
		{
			int index = std::distance(numbers.begin(), result);
			std::cout << "Found " << nbr_to_find << " at index " << index << std::endl;
			std::cout << "Return from funtion is " << *result << std::endl;
		}
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	
	//Not finding
	std::cout << RED;
	try {
		
		std::vector<int>::iterator result = easyfind(numbers, wrong_nbr_to_find);
		if (result != numbers.end())
		{
			std::cout << "Found " << wrong_nbr_to_find << " at index " << *result << std::endl;
			std::cout << "Return from funtion is " << *result << std::endl;
		}
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << RESET;
}
