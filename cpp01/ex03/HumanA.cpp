/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:52:56 by jmarinho          #+#    #+#             */
/*   Updated: 2024/01/25 17:27:07 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : nameA(name), WeaponA(weapon) {}


HumanA::~HumanA() {
}

void HumanA::attack() const
{
    std::cout << this->nameA << " attacks with their " << WeaponA.getType() << std::endl;
}
