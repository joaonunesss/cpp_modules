/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:18:51 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/30 11:54:07 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
    std::cout << "Animal default constructor called!" << std::endl;
    type = "Default_type";
}

Animal::~Animal(){
    std::cout << "Animal default destructor called!" << std::endl;
}

Animal::Animal(std::string other_type){
    std::cout << "Animal default constructor called!" << std::endl;
    type = other_type;
}

Animal::Animal(const Animal &other){
    std::cout << "Animal copy constructor called!" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal &other){
    std::cout << "Animal copy assignment operator called!" << std::endl;
    type = other.type;
    return *this;
}

const std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
        std::cout << "Default animal sound... GRRRRRR" << std::endl;
}