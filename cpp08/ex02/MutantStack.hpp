/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:05:34 by jmarinho          #+#    #+#             */
/*   Updated: 2024/08/13 16:04:26 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <stack>
#include <deque>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[36m"
# define RESET "\033[37m"

template <typename T>
class MutantStack : public std::stack<T> {

	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack&operator=(const MutantStack &other);

		typedef typename std::deque<T>::iterator iterator;

		typename std::deque<T>::iterator begin();
		typename std::deque<T>::iterator end();
};

#endif

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
}

template <typename T>
MutantStack<T>::~MutantStack() {
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other) {
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
	if (this != other)
		std::stack<T>::operator=(other);

	return *this;
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::begin() {
    return std::stack<T>::c.begin();
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::end() {
    return std::stack<T>::c.end();
}