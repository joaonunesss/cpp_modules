/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:15:54 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/09 12:49:59 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructor called!" << std::endl;
    name = "Default_Scav";
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap default destructor called!" << std::endl;
}

ScavTrap::ScavTrap(std::string other_name) : ClapTrap(other_name) {
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap copy assignment operator called!" << std::endl;
    if (this != &other) {
        name = other.name;
    }
    return *this;
}

void ScavTrap::attack(const std::string& target) {
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

void ScavTrap::guardGate() {
    std::cout << name << " is now in Gate keeper mode." << std::endl;
}
