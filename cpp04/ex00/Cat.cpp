/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:53:28 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/12 11:53:28 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"


Cat::Cat() : Animal() {
    std::cout << "Cat default constructor called!" << std::endl;
    type = "Cat";
}

Cat::~Cat() {
    std::cout << "Cat default destructor called!" << std::endl;
}

Cat::Cat(std::string other_type)  : Animal(other_type) {
    std::cout << "Cat default constructor called!" << std::endl;
    type = other_type;
}

Cat::Cat(const Cat &other)  : Animal(other) {
    std::cout << "Cat copy constructor called!" << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat &other) {
    std::cout << "Cat copy assignment operator called!" << std::endl;
    type = other.type;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Cat makes miau, miau!" << std::endl;
}