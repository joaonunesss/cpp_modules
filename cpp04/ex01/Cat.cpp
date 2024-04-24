/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:53:28 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/15 14:04:59 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"


Cat::Cat() : Animal() {
    std::cout << "Cat default constructor called!" << std::endl;
    type = "Cat";
    cat_brain = new Brain();
}

Cat::~Cat() {
    std::cout << "Cat default destructor called!" << std::endl;
    delete cat_brain;
}

Cat::Cat(const Cat &other)  : Animal(other) {
    std::cout << "Cat copy constructor called!" << std::endl;
            
    *this = other;
}

Cat& Cat::operator=(const Cat &other) {
    std::cout << "Cat copy assignment operator called!" << std::endl;
    
    type = other.type;  
    
    cat_brain = new Brain(*other.cat_brain);
    
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Cat makes miau, miau!" << std::endl;
}
