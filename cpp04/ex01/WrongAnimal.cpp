/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:04:43 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/12 12:04:48 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    std::cout << "WrongAnimal default constructor called!" << std::endl;
    type = "WrongAnimal_type";
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal default destructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string other_type){
    std::cout << "WrongAnimal default constructor called!" << std::endl;
    type = other_type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other){
    std::cout << "WrongAnimal copy constructor called!" << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other){
    std::cout << "WrongAnimal copy assignment operator called!" << std::endl;
    type = other.type;
    return *this;
}

const std::string WrongAnimal::getType() const {
    return type;
}

void WrongAnimal::makeSound() const {
        std::cout << "Default WrongAnimal sound... GRRRRRR" << std::endl;
}