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

Span::Span() : size(0) {
	std::cout << "Default constructor called" << std::endl;
}

Span::~Span() {
	std::cout << "Default desconstructor called" << std::endl;
}

Span::Span(const Span &other) {
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

Span& Span::operator=(const Span &other) {
	if (this != &other)
	{
		numbers = other.numbers;
		size = other.size;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Span::Span(unsigned int N) : size(N) {
	
	std::cout << GREEN;
	std::cout << "Container numbers init with " << N << " elements" << std::endl;
	std::cout << RESET;
}

void	Span::addNumber(int nbr) {
	
	if (numbers.size() >= size)
		throw FullContainer();
	numbers.push_back(nbr);
}

void	Span::addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end, std::vector<int> numbersToAdd)
{
	if (numbersToAdd.size() > size)
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
	
	if (size < 2)
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
