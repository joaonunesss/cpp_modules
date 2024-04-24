/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:04:57 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/12 12:05:01 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal() {
    std::cout << "WrongCat default constructor called!" << std::endl;
    type = "WrongCat";
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat default destructor called!" << std::endl;
}

WrongCat::WrongCat(std::string other_type)  : WrongAnimal(other_type) {
    std::cout << "WrongCat default constructor called!" << std::endl;
    type = other_type;
}

WrongCat::WrongCat(const WrongCat &other)  : WrongAnimal(other) {
    std::cout << "WrongCat copy constructor called!" << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat &other) {
    std::cout << "WrongCat copy assignment operator called!" << std::endl;
    type = other.type;
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "WrongCat makes miau, miau!" << std::endl;
}