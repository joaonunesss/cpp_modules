/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:12:42 by jmarinho          #+#    #+#             */
/*   Updated: 2024/09/17 14:07:20 by jmarinho         ###   ########.fr       */
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
}
