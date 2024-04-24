/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:27:39 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/23 16:41:57 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Character::Character() {
    std::cout << "Character default constructor called!" << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    for (int i = 0; i < 99; i++)
        unequip_list[i] = NULL;
    name = "Default_Character";
}

Character::~Character() {

    std::cout << "Character default destructor called!" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
        {
            delete inventory[i];
            inventory[i] = NULL;  
            std::cout << RED << "Inventory slot deleted!" << RESET << std::endl;
        }
    }
    for (int i = 0; i < 99; i++)
    {
        if (unequip_list[i])
        {
            delete unequip_list[i];
            unequip_list[i] = NULL;  
            std::cout << RED << "Unequip slot deleted" << RESET << std::endl;
        }
    }
}

Character::Character(const std::string &other_name) {
    std::cout << "Character name constructor called and ";
    std::cout << other_name << " name is set" << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    for (int i = 0; i < 99; i++)
        unequip_list[i] = NULL;
    name = other_name;
}

Character::Character(const Character &other){
    std::cout << "Character copy constructor called!" << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    for (int i = 0; i < 99; i++)
        unequip_list[i] = NULL;
    *this = other;
}

Character& Character::operator=(const Character &other){
    std::cout << "Character copy operator called!" << std::endl;
    name = other.name;
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
    }
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i] != NULL)
            inventory[i] = other.inventory[i]->clone();   
    }
    return *this;
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    
    if (m->flag_equiped == 1)
    {
        std::cout << RED << "Danger! Materia pointer already equiped!" << RESET << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            std::cout << "Character equiping...";
            std::cout << GREEN << m->getType() << RESET << std::endl;
            inventory[i] = m;
            m->flag_equiped = 1;
            return ;
        }
    }
    std::cout << "Character inventory full!" << std::endl;
}

void Character::unequip(int idx){
    
    static int k = 0;

    if (!inventory[idx])
    {
        std::cout << RED << "Oh No! No materia equipped to unequip!" << RESET << std::endl;
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        unequip_list[k++] = inventory[idx];
        break;
    }

    std::cout << RED << inventory[idx]->getType() << RESET;
    std::cout << " unequipped from inventory from slot ";
    std::cout << RED << idx << RESET << std::endl;

    inventory[idx] = NULL;

}

void Character::use(int idx, ICharacter& target){
    

    if (!inventory[idx])
    {
        std::cout << RED << "Oh No! No materia equiped to use!" << RESET << std::endl;
        return ;
    }
    inventory[idx]->use(target);
    std::cout << GREEN << inventory[idx]->getType() << RESET;
    std::cout << " used in ";
    std::cout << GREEN << target.getName() << RESET << std::endl;
}
