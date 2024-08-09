/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:40:18 by jmarinho          #+#    #+#             */
/*   Updated: 2024/08/09 13:42:58 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* PRINT AND CONVERT */

static void print_if_Char(char ch)
{
    std::cout << "char: '" << ch << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(ch) << std::endl;
    std::cout << "float: " << static_cast<float>(ch) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(ch) << ".0" << std::endl;
}

static void print_if_Int(int nbr)
{
    if (isprint(nbr))
        std::cout << "char: '" << static_cast<char>(nbr)  << "'" << std::endl; 
    else
        std::cout << "char: Non displayable" << std::endl; 
    std::cout << "int: " << nbr << std::endl;
    std::cout << "float: " << static_cast<float>(nbr) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(nbr) << ".0" << std::endl;
}

static void print_if_Float(float nbr)
{
    if (isprint(nbr))
        std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(nbr) << std::endl;
    std::cout << "float: " << nbr << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(nbr) << ".0" << std::endl;
}

static void print_if_Double(double nbr)
{
    if (isprint(nbr))
        std::cout << "char: '" << static_cast<char>(nbr)  << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(nbr) << std::endl;
    std::cout << "float: " << static_cast<float>(nbr) << ".0f" << std::endl;
    std::cout << "double: " << nbr << ".0" << std::endl;
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
	std::cout << "float: " << limits << "f" << std::endl;
	std::cout << "double: " << limits << std::endl;
}

/* DETECT WICH TYPE IS PASSED */

bool detectChar(std::string literal)
{
    if (literal.length() != 1 || isdigit(literal[0]))
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
        if (!isdigit(literal[i]))
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
    while (literal[++i])
    {
        if (literal[i] == '.' && flag)
            return false;
        else if (literal[i] == '.')
        {
            flag = true;
            continue;
        }
        if (!isdigit(literal[i]) && i != (int)(literal.length() - 1))
            return false;
    }
    return true;
}

bool detectDouble(std::string literal)
{
	int i = -1;
	bool   flag = false;

	 while (literal[++i])
    {
        if (literal[i] == '.' && flag)
            return false;
        else if (literal[i] == '.')
        {
            flag = true;
            continue;
        }
        if (!isdigit(literal[i]))
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
		return 4;
}

/* CHOOSE RIGHT FUNCTION BY TYPE */

void ScalarConverter::convert(std::string literal)
{
    double limits;

    limits = strtod(literal.c_str(), NULL);
    if (limits > INT_MAX || limits < INT_MIN)
        printLimitDouble(limits);
	else if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		printLiteralFloat(literal);
	else if (literal == "-inf" || literal == "+inf" || literal == "nan")
		printLiteralDouble(literal);
    else
    {
        switch (actualType(literal))
        {
            case 0:
                print_if_Char(literal[0]);
                break;
            
            case 1:
                print_if_Int(atoi(literal.c_str()));
                break;

            case 2:
                print_if_Float(atof(literal.c_str()));
                break;
            
            case 3:
                print_if_Double(strtod(literal.c_str(), NULL));
                break;
            
            default:
                std::cout << "Invalid input" << std::endl;
                break;    
        }
    }
}
