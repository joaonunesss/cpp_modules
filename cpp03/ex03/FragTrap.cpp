/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:03:31 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/18 15:10:10 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string set_name):ClapTrap(set_name){
    std::cout << "FragTrap Default constructor called" << std::endl;
    new_name = set_name;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &other):ClapTrap(other){
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = other;
}

void FragTrap::attack(const std::string& target){
    std::cout << "FragTrap " << new_name << " attack " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void){
    std::cout << "FragTrap wants to high five you!" << std::endl;
}