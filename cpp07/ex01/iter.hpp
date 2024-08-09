/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:07:18 by jmarinho          #+#    #+#             */
/*   Updated: 2024/08/09 17:17:51 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void print_elements_of_array(T &element)
{
	std::cout << element << std::endl;
}


template <typename T>
void iter(T *array, size_t length, void (*func)(T &))
{
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}


#endif