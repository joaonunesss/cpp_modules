/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:12:08 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/18 16:28:01 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


DiamondTrap::DiamondTrap(std::string set_name):ClapTrap(set_name), ScavTrap(set_name), FragTrap(set_name){
    std::cout << "DiamondTrap Default constructor called" << std::endl;
    new_name = set_name;
    ClapTrap::new_name = set_name + "_clap_name";
    ClapTrap::hitpoints = 100;
    ClapTrap::energyPoints = 50;
    ClapTrap::attackDamage = 30;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const &other):ClapTrap(other), ScavTrap(other), FragTrap(other){
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
    *this = other;
}

void DiamondTrap::printpoints(){
    std::cout << "DiamondTrap Hit points are " << FragTrap::hitpoints << ", Energy points are " <<
        ScavTrap::energyPoints << ", Attack damage is " << FragTrap::attackDamage << std::endl;
}

/*void DiamondTrap::attack(const std::string &target){
    ScavTrap::attack(target);
}*/

void DiamondTrap::whoAmI(){
    std::cout << "DiamondTrap name is " << new_name << std::endl;
    std::cout << "ClapTrap name is " << ClapTrap::new_name << std::endl;
}