/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:13:42 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/19 14:28:17 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():Animal()
{
    std::cout << "Dog Constructor called" << std::endl;
    this->type = "Bobbi";
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(Dog &other)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    this->type = other.type;
}

void Dog::makeSound() const
{
    std::cout << "Au, au, au" << std::endl;
}