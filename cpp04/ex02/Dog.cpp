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

#include "A_Animal.hpp"
#include "Dog.hpp"


Dog::Dog() : A_Animal() {
    std::cout << "Dog default constructor called!" << std::endl;
    type = "Dog";
    dog_brain = new Brain();
}

Dog::~Dog() {
    std::cout << "Dog default destructor called!" << std::endl;
    delete dog_brain;
}

Dog::Dog(const Dog &other) : A_Animal(other) {
    std::cout << "Dog copy constructor called!" << std::endl;

    *this = other;
}

Dog& Dog::operator=(const Dog &other) {
    std::cout << "Dog copy assignment operator called!" << std::endl;

    type = other.type;

    dog_brain = new Brain(*other.dog_brain);

    return *this;
}

void Dog::makeSound() const {
    std::cout << "Dog makes auf, auf!" << std::endl;
}
