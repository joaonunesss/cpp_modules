/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:37:05 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/19 14:41:29 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal()
{
    std::cout << "WrongCat Constructor called" << std::endl;
    this->type = "WrongWhiskas";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat &other)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    this->type = other.type;
}

void WrongCat::makeSound() const
{
    std::cout << "grr" << std::endl;
}