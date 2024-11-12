/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:46:08 by jmarinho          #+#    #+#             */
/*   Updated: 2024/09/11 13:55:37 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Invalid number of args!" << std::endl;
		return EXIT_FAILURE;
	}

	if (!RPN::isValid(av[1]))
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
	
}