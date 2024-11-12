/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:44:13 by jmarinho          #+#    #+#             */
/*   Updated: 2024/08/13 13:15:52 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[36m"
# define RESET "\033[37m"

class Span {
	public:
		Span();
		~Span();
		Span(const Span &other);
		Span&operator=(const Span &other);

		Span(unsigned int N);

		void addNumber(int nbr);
		int shortestSpan();
		int longestSpan();

		void	addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end, std::vector<int> numbersToAdd);


		std::vector<int> numbers;
		unsigned int size;

		class FullContainer : public std::exception {
			public:
				char const *what() const throw();
		};

		class NotEnoughN : public std::exception {
			public:
				char const *what() const throw();
		};
};

#endif