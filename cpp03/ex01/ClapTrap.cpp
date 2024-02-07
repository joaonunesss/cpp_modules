/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:24:23 by jmarinho          #+#    #+#             */
/*   Updated: 2024/02/07 10:39:44 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string set_name){
    std::cout << "ClapTrap Default constructor called" << std::endl;
    new_name = set_name;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &other){
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = other;
}

void ClapTrap::attack(const std::string& target){
    std::cout << "ClapTrap " << new_name << " attack " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount){
    std::cout << "ClapTrap " << new_name << " take " << amount << " points of damage!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount){
    std::cout << "ClapTrap " << new_name << " be repaired " << amount << " points of damage!" << std::endl;
}
