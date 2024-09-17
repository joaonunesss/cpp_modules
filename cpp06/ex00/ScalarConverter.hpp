/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:13:21 by jmarinho          #+#    #+#             */
/*   Updated: 2024/09/17 11:52:47 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <cmath>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

class ScalarConverter {
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter&operator=(const ScalarConverter &other);

	public:	
		static void convert(std::string literal);
};

#endif