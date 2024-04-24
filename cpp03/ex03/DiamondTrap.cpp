/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:44:51 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/15 14:36:08 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    std::cout << "DiamondTrap default constructor called" << std::endl;
    name = "Default_Diamond";
    ClapTrap::name = name + "_clap_name";
    hit_points = FragTrap::hit_points;
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(std::string other_name) {
    std::cout << "DiamondTrap name constructor called" << std::endl;
    name = other_name;
    ClapTrap::name = other_name + "_clap_name";
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap default destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target){
    ScavTrap::attack(target);
}

DiamondTrap::DiamondTrap(const DiamondTrap &other ) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other){
    std::cout << "DiamondTrap copy assignment operator called!" << std::endl;
    ClapTrap::operator=(other);
    name = other.name;
    return *this;
}

void DiamondTrap::whoAmI(){
    std::cout << std::endl;
    std::cout << "My name is " << name << " and I'm a DiamondTrap" << std::endl;
    std::cout << "My name is " << ClapTrap::name << " and I'm a ClapTrap" << std::endl;
}