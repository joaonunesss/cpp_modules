/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:20:59 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/19 14:28:12 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():Animal()
{
    std::cout << "Cat Constructor called" << std::endl;
    this->type = "Whiskas";
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(Cat &other)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    this->type = other.type;
}

void Cat::makeSound() const
{
    std::cout << "Miau, miau, miau" << std::endl;
}