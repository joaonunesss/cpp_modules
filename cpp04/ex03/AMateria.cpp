/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:21:05 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/23 16:39:25 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() {
    std::cout << "AMateria default constructor called!" << std::endl;
    type = "default_type";
    flag_equiped = 0;
}

AMateria::~AMateria() {
    std::cout << "AMateria default destructor called!" << std::endl;
}

AMateria::AMateria(std::string const &type) {
    std::cout << "AMateria copy constructor called!" << std::endl;
    this->type = type;
    flag_equiped = 0;
}

AMateria::AMateria(const AMateria &other) {
    std::cout << "AMateria copy assignment called!" << std::endl;    
    *this = other;
}

AMateria& AMateria::operator=(const AMateria &other) {
    std::cout << "AMateria copy operator called!" << std::endl;    
    type = other.type;
    flag_equiped = other.flag_equiped;
    return *this;
}

std::string const& AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target){
    (void) target;
}