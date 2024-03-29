/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:53:34 by jmarinho          #+#    #+#             */
/*   Updated: 2024/01/25 17:27:15 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : nameB(name), WeaponB(NULL) {  
}

HumanB::~HumanB() {
}

void HumanB::attack() const
{
    std::cout << this->nameB << " attacks with ";
    if (WeaponB != NULL)
        std::cout << "their " << WeaponB->getType() << std::endl;
    else
        std::cout << "no weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    WeaponB = &weapon;
}
