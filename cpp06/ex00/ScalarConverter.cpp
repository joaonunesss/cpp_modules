/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:40:18 by jmarinho          #+#    #+#             */
/*   Updated: 2024/09/17 14:08:49 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* PRINT AND CONVERT */

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other){
	*this = other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
	(void) other;
	return *this;
}

static void printIfChar(char ch)
{
    std::cout << "char: '" << ch << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(ch) << std::endl;
    std::cout << "float: " << static_cast<float>(ch) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(ch) << ".0" << std::endl;
}

static void printIfInt(int nbr)
{
    if (isprint(nbr))
        std::cout << "char: '" << static_cast<char>(nbr)  << "'" << std::endl; 
    else
        std::cout << "char: Non displayable" << std::endl; 
    std::cout << "int: " << nbr << std::endl;
    std::cout << "float: " << static_cast<float>(nbr) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(nbr) << ".0" << std::endl;
}

static void printIfFloat(float nbr)
{
	double fractionalPart, intPart;

	fractionalPart = std::modf(nbr, &intPart);
    if (isprint(nbr))
        std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	if (fractionalPart == 0)
	{
		std::cout << "float: " << nbr << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(nbr) << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << nbr << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(nbr) << std::endl;
	}
}

static void printIfDouble(double nbr)
{
	double fractionalPart, intPart;

	fractionalPart = std::modf(nbr, &intPart);
    if (isprint(nbr))
        std::cout << "char: '" << static_cast<char>(nbr)  << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	if (fractionalPart == 0)
	{
		std::cout << "float: " << static_cast<float>(nbr) << ".0f" << std::endl;
		std::cout << "double: " << nbr << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(nbr) << "f" << std::endl;
		std::cout << "double: " << nbr << std::endl;
	}
}

static void printLiteralFloat(std::string literal)
{
	size_t i = -1;

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal << std::endl;
	std::cout << "double: ";
	while (++i < (literal.length() - 1))
		std::cout << literal[i];
	std::cout << std::endl;
}

static void printLiteralDouble(std::string literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal << "f" << std::endl;
	std::cout << "double: " << literal << std::endl;
}

static void printLimitDouble(double limits)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(limits) << "f" << std::endl;
	std::cout << "double: " << limits << std::endl;
}

/* DETECT WICH TYPE IS PASSED */

bool detectChar(std::string literal)
{
    if (literal.length() != 1 || std::isdigit(literal[0]))
        return false;
    return true;
}

bool detectInt(std::string literal)
{
    int i = 0;

    if (literal.at(0) == '-')
        i = 1;
    while (literal[i])
    {
        if (!std::isdigit(literal[i]))
            return false;
        i++;
    }
    return true; 
}

bool detectFloat(std::string literal)
{
    bool    flag = false;
	int     i = -1;

    if (literal[literal.length() - 1] != 'f')
        return false;
	else if (literal.at(0) == '-')
        i = 1;
    while (literal[++i])
    {
        if (literal[i] == '.' && flag)
            return false;
        else if (literal[i] == '.')
        {
            flag = true;
            continue;
        }
        if (!std::isdigit(literal[i]) && i != (int)(literal.length() - 1))
            return false;
    }
    return true;
}

bool detectDouble(std::string literal)
{
	int i = -1;
	bool   flag = false;

	if (literal.at(0) == '-')
       		i = 0;
	while (literal[++i])
    {
        if (literal[i] == '.' && flag)
            return false;
        else if (literal[i] == '.')
        {
            flag = true;
            continue;
        }
        if (!std::isdigit(literal[i]))
            return false;
    }
    return true;
}

/* PICK RIGHT TYPE */

int actualType(std::string literal)
{
    if (detectChar(literal))
        return 0;
    else if (detectInt(literal))
        return 1;
    else if (detectFloat(literal))
        return 2;
    else if (detectDouble(literal))
        return 3;    
	else
		return 7;
}

int actualLimits(std::string literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return 4;
	else if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return 5;
	return 7;
}

/* CHOOSE RIGHT FUNCTION BY TYPE */

void ScalarConverter::convert(std::string literal)
{
	double limits;

    limits = strtod(literal.c_str(), NULL);
	if (limits >= INT_MAX || limits <= INT_MIN)
	{
		printLimitDouble(limits);
        return;
	}

	switch (actualType(literal))
	{
		case 0:
			printIfChar(literal[0]);
			return;
		
		case 1:
			printIfInt(atoi(literal.c_str()));
			return;

		case 2:
			printIfFloat(atof(literal.c_str()));
			return;
		
		case 3:
			printIfDouble(strtod(literal.c_str(), NULL));
			return;
		    
	}
	
	switch (actualLimits(literal))
	{
		case 4:
			printLiteralFloat(literal);
			break;

		case 5:
			printLiteralDouble(literal);
			break;
		
		case 7:
			std::cout << "Invalid input" << std::endl;
			break;
	}
}
