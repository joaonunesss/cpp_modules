/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_A_Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:18:51 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/15 14:42:25 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.hpp"

A_Animal::A_Animal(){
    std::cout << "A_Animal default constructor called!" << std::endl;
    type = "Default_type";
}

A_Animal::~A_Animal(){
    std::cout << "A_Animal default destructor called!" << std::endl;
}

A_Animal::A_Animal(std::string other_type){
    std::cout << "A_Animal default constructor called!" << std::endl;
    type = other_type;
}

A_Animal::A_Animal(const A_Animal &other){
    std::cout << "A_Animal copy constructor called!" << std::endl;
    *this = other;
}

A_Animal& A_Animal::operator=(const A_Animal &other){
    std::cout << "A_Animal copy assignment operator called!" << std::endl;
    type = other.type;
    return *this;
}

const std::string A_Animal::getType() const {
    return type;
}
