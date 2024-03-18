/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:21:43 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/18 14:46:16 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string set_name):ClapTrap(set_name){
    std::cout << "ScavTrap Default constructor called" << std::endl;
    new_name = set_name;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other):ClapTrap(other){
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    *this = other;
}

void ScavTrap::attack(const std::string& target){
    std::cout << "ScavTrap " << new_name << " attack " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}