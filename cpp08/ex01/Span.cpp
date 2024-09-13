/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:44:08 by jmarinho          #+#    #+#             */
/*   Updated: 2024/08/13 14:02:21 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : numbers(0), N(N) {
	
	std::cout << GREEN;
	std::cout << "Container numbers init with " << N << " elements" << std::endl;
	std::cout << RESET;
}

void	Span::addNumber(int nbr) {
	
	if (numbers.size() == N)
		throw FullContainer();
	numbers.push_back(nbr);

	std::cout << BLUE;
	std::cout << "Number " << nbr << " added to the container" << std::endl;
	std::cout << RESET;
}

void 	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
		
    if (numbers.size() == N)
        throw FullContainer();

    numbers.insert(numbers.end(), begin, end);
}


int		Span::shortestSpan() {
	
	int shortest;
	int span;

	if (numbers.size() < 2)
		throw NotEnoughN();
	std::sort(numbers.begin(), numbers.end());

	shortest = numbers.at(1) - numbers.at(0);

	std::vector<int>::iterator i;
	for (unsigned int i = 0; i < numbers.size() - 1; i++)
	{
		span = numbers[i + 1] - numbers[i];
		if (span < shortest)
			shortest = span;
	}

	return shortest;
}

int		Span::longestSpan() {
	
	if (N < 2)
		throw NotEnoughN();
	std::sort(numbers.begin(), numbers.end());
	
	return numbers[numbers.size() - 1] - numbers[0];
}

char const *Span::FullContainer::what() const throw() {
	return "Error! \nMax nbr of elements already stored";
}

char const *Span::NotEnoughN::what() const throw() {
	return "Error!\nNo span can be found. No numbers stored or only one";
}
