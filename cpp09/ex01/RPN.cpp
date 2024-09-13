/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:43:06 by jmarinho          #+#    #+#             */
/*   Updated: 2024/09/11 14:36:51 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN& RPN::operator=(const RPN &other)
{
	(void) other;
	return *this;
}

bool	RPN::isValid(std::string str)
{
	if (str.find_first_not_of("0123456789+-*/ ") == std::string::npos)
		return true;
	std::cerr << "Error. Invalid chars detected." << std::endl;
	return false;
}

double	choseOperation(char token, double a, double b)
{
	switch (token) {
		case '+' :
			return a + b;
		case '-' :
			return a - b;
		case '/' :
			return a / b;
		case '*' :
			return a * b;
	}
	return EXIT_FAILURE;
}

double	RPN::calculate_rpn(std::string str)
{
	std::string token;
	double a, b;
	
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ' || str[i] == '\t')
			continue ;

		if (std::isdigit(str[i]))
		{	
			token.clear();
			
			while (i < str.length() && isdigit(str[i]))
				token += str[i++];
				
			stack.push(atof(token.c_str()));
			i--;
		}
 		if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
		{
			if (str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '/' || str[i + 1] == '*')
			{
				std::cerr << "Error. Invalid operator in expression." << std::endl;
				return EXIT_FAILURE;
			}
 			if (stack.size() < 2)
			{
				if (std::isdigit(str[i + 1]))
				{
					std::cerr << "Error. Negative numbers not accepted." << std::endl;
					return EXIT_FAILURE;
				}
				std::cerr << "Error. Not enough numbers." << std::endl;
				return EXIT_FAILURE;
			}
			b = stack.top(); stack.pop();
			a = stack.top(); stack.pop();
			if (str[i] == '/' && b == 0)
			{
				std::cerr << "Error. Cannot divide by zero." << std::endl;
				return EXIT_FAILURE;
			}	
			result = choseOperation(str[i], a, b);
			stack.push(result);
		}
	}
	
	if (stack.size() !=  1)
	{
		std::cerr << "Error. Invalid RPN expression." << std::endl;
		return EXIT_FAILURE;
	}
	
	std::cout << "Result : " << stack.top() << std::endl;

	return EXIT_SUCCESS;
}
