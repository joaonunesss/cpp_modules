/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:15:39 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/08 16:47:52 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    std::cout << "ClapTrap default constructor called!" << std::endl;
    name = "Default_name";
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap default destructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string other_name){
    name = other_name;
}

ClapTrap::ClapTrap(const ClapTrap &other){
    std::cout << "Copy constructor called!" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other){
    std::cout << "Copy assignment operator called!" << std::endl;
    if (this != &other) {
        name = other.name;
    }
    return *this;
}

void ClapTrap::attack(const std::string &target){
    if (energy_points-- > 0 && hit_points > 0)
    {
        std::cout << name << " attacks ";
        std::cout << target << " causing " << attack_damage << " points of damage!" << std::endl;
    }
    else if (energy_points <= 0)
        std::cout << "No energy points left!" << std::endl;
    else if (hit_points <= 0)
        std::cout << "No hit points left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
        std::cout << name << " takes ";
        std::cout << amount << " points of damage!" << std::endl;
        hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (energy_points-- > 0)
    {
        std::cout << name << " gets ";
        std::cout << amount << " hit points back!" << std::endl;
        hit_points += amount;
    }
    else
        std::cout << "No energy points left!" << std::endl;
}
