/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:00:02 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/27 17:24:29 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "The memory address of the string variable: "<< &str << std::endl;
    std::cout << "The memory address held by stringPTR: "<< stringPTR << std::endl;
    std::cout << "The memory address held by stringREF: "<< &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "Value of the string variable: "<< str << std::endl;
    std::cout << "Value pointed to by stringPTR: "<< *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: "<< stringREF << std::endl;
}
