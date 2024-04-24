/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:03:31 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/15 14:24:55 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
    std::cout << "FragTrap default constructor called" << std::endl;
    name = "Default_Frag";
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(std::string other_name) : ClapTrap(other_name){
    std::cout << "FragTrap name constructor called" << std::endl;
    name = other_name;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other){
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap copy assignment operator called!" << std::endl;
    if (this != &other) {
        name = other.name;
    }
    return *this;
}

void FragTrap::attack(const std::string& target) {
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

void FragTrap::highFivesGuys(void) {
    std::cout << name << " is now giving a positive high five!" << std::endl;
}