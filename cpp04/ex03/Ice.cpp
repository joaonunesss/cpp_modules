/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:25:10 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/23 15:07:56 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(){
    std::cout << "Ice default constructor called!" << std::endl;
    type = "ice";
}

Ice::~Ice(){
    std::cout << "Ice default destructor called!" << std::endl;
}

Ice::Ice(const Ice &other){
    std::cout << "Ice copy constructor called!" << std::endl;
    *this = other;
}

Ice& Ice::operator=(const Ice &other){
    std::cout << "Ice copy operator called!" << std::endl;
    type = other.type;
    return *this;
}

AMateria* Ice::clone() const {
    std::cout << "Ice clone created" << std::endl;
    return new Ice();
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}