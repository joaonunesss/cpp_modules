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
	int nbr_of_elements = 11000;

	
	Span sp = Span(nbr_of_elements);
	std::vector<int> vector(nbr_of_elements);
	
	srand(time(NULL));
	for(int i = 0; i < (int)vector.size(); i++)
		vector[i] = rand();

	try
	{
		sp.addNumber(vector.begin(), vector.end());
		std::cout << "Shortest span is " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span is " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e) {
		std::cerr << RED;
		std::cerr << e.what() << std::endl;
		std::cerr << RESET;
	}

/*  	//TRYING TO SORT ONLY ONE NBR
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
	
	//TRYING TO ADD ONE MORE NBR
	try
	{
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(23);//element out of bounds
	}
	catch(const std::exception &e){
		std::cerr << RED;
		std::cerr << e.what() << std::endl;
		std::cerr << RESET;
	}
	
	//SORTING NBRS ADDED RETURNING SHORTEST AND LONGEST
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

/* 	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl; */
}
