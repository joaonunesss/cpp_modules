/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:25:59 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/22 14:27:17 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(){
    std::cout << "Cure default constructor called!" << std::endl;
    type = "cure";
}

Cure::~Cure(){
    std::cout << "Cure default destructor called!" << std::endl;
}

Cure::Cure(const Cure &other){
    std::cout << "Cure copy constructor called!" << std::endl;
    *this = other;
}
Cure& Cure::operator=(const Cure &other){
    std::cout << "Cure copy operator called!" << std::endl;
    type = other.type;

    return *this;
}

AMateria* Cure::clone() const {
    std::cout << "Ice clone created" << std::endl;
    return new Cure();
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}
