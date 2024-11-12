/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:12:42 by jmarinho          #+#    #+#             */
/*   Updated: 2024/08/13 13:26:19 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[36m"
# define RESET "\033[37m"

int main()
{
	   					//TRYING TO SORT MORE THAN 10000 NBRS

	int nbr_of_elements = 11000;

	
	Span sp(nbr_of_elements);
	
 	try
	{
		for(unsigned int i = 0; i < sp.size; i++)
			sp.addNumber(i);
		std::cout << "Shortest span is " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span is " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e) {
		std::cerr << RED;
		std::cerr << e.what() << std::endl;
		std::cerr << RESET;
	}

   					//TRYING TO SORT ONLY ONE NBR

/* 	int nbr_of_elements = 1;
	
	Span sp(nbr_of_elements);

	try
	{
		sp.addNumber(6);
		std::cout << "Shortest span is " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span is " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e){
		std::cerr << RED;
		std::cerr << e.what() << std::endl;
		std::cerr << RESET;
	}
	 */
/* 					//TRYING TO ADD MORE NBR
	int nbr_of_elements = 4;
	
	Span sp(nbr_of_elements);

	try
	{
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		//sp.addNumber(23);//element out of bounds
		std::cout << "Shortest span is " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span is " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e){
		std::cerr << RED;
		std::cerr << e.what() << std::endl;
		std::cerr << RESET;
	} */

					//ADDING NBR TO VECTOR IN A EFFICIENT WAY

/* 	int nbr_of_elements = 10;
	
	Span sp(nbr_of_elements);

	std::vector<int> numbersToAdd;
	for(int i = 0; i < nbr_of_elements; i++)
    	numbersToAdd.push_back(i * 10);
	
	try
	{
		sp.addManyNumbers(numbersToAdd.begin(), numbersToAdd.end(), numbersToAdd);
	}
	catch(const std::exception &e){
        std::cerr << RED;
		std::cerr << e.what() << std::endl;
		std::cerr << RESET;
    }

    try
	{
		std::cout << "Shortest span is " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span is " << sp.longestSpan() << std::endl;
    }
	catch(const std::exception &e){
        std::cerr << RED;
		std::cerr << e.what() << std::endl;
		std::cerr << RESET;
    } */
}
