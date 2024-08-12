/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:07:18 by jmarinho          #+#    #+#             */
/*   Updated: 2024/08/12 15:07:21 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>


# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[36m"
# define RESET "\033[37m"

template <typename T>
class Array {
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(Array &other);
		Array &operator=(Array &other);

		T &operator[](unsigned int index);

		unsigned int size();

		class Out_Of_Bounds : public std::exception {
			public:
				virtual const char *what() const throw();
		};
	
	private:
		T *array;
		unsigned int array_size;
};

#endif

template<typename T>
Array<T>::Array() : array(new T[0]()), array_size(0) {
	std::cout << GREEN << "Default Constructor has been called" << RESET << std::endl;
}

template<typename T>
Array<T>::~Array() {
	delete[] array;
	std::cout << RED << "Default Destructor has been called" << RESET << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n) : array(new T[n]()), array_size(n) {
	std::cout << BLUE << "Default Param Constructor has been called" << RESET << std::endl;
}

template<typename T>
Array<T>::Array(Array &other) : array(new T[other.n]()), array_size(other.n){
	*this = other;
	std::cout << YELLOW << "Default Copy Constructor has been called" << RESET << std::endl;
}

template<typename T>
Array<T> &Array<T>::operator=(Array &other) {
	if (this != &other)
	{
		delete[] this->array;
		this->array = new T[other.array_size]();
		this->array_size = other.array_size;
		for (unsigned int i = 0; i < other.array_size; i++)
			this->array[i] = other.array[i];
	}
	std::cout << BLUE << "Default Assignment Operator has been called" << RESET << std::endl;
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= this->array_size || index < 0)
		throw Out_Of_Bounds();
	//std::cout << BLUE << "Default Subscript Operator has been called" << RESET << std::endl;
	return this->array[index];
}

template<typename T>
char const *Array<T>::Out_Of_Bounds::what() const throw() {
	return "Index out of bounds";
}

template<typename T>
unsigned int Array<T>::size() {
	return array_size;
}
