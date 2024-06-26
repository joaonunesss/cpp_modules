/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:18:51 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/11 14:27:37 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"


Dog::Dog() : Animal() {
    std::cout << "Dog default constructor called!" << std::endl;
    type = "Dog";
}

Dog::~Dog() {
    std::cout << "Dog default destructor called!" << std::endl;
}

Dog::Dog(std::string other_type) : Animal(other_type) {
    std::cout << "Dog default constructor called!" << std::endl;
    type = other_type;
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog copy constructor called!" << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog &other) {
    std::cout << "Dog copy assignment operator called!" << std::endl;
    type = other.type;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Dog makes auf, auf!" << std::endl;
}
