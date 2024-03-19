/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:07:03 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/19 14:15:45 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Constructor called" << std::endl;
    this->type = "Default";
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(Animal &other)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    this->type = other.type;
}

std::string Animal::getType() const
{    
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}