/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:36:10 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/19 14:36:54 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Constructor called" << std::endl;
    this->type = "WrongDefault";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &other)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    this->type = other.type;
}

std::string WrongAnimal::getType() const
{    
    return this->type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}