/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:12:42 by jmarinho          #+#    #+#             */
/*   Updated: 2024/08/09 13:44:21 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{    
		if (ac != 2 || !av[1][0])
		{
			std::cerr << "ERROR\nWrong nbr of arguments" << std::endl;
			return (1);
		}
	ScalarConverter::convert(av[1]);
	
/* 
	(void)ac; (void) av;
	std::cout << "./convert 0" << std::endl;
	std::string str = "0";
	ScalarConverter::convert(str);

	std::cout << "./convert nan" << std::endl;
	str = "nan";
	ScalarConverter::convert(str);

	std::cout << "./convert 42.0f" << std::endl;
	str = "42.0f";
	ScalarConverter::convert(str);

	std::cout << "./convert *" << std::endl;
	str = "*";
	ScalarConverter::convert(str);

	std::cout << "./convert 2147483648" << std::endl;
	str = "2147483648";
	ScalarConverter::convert(str); */
}
