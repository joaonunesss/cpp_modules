/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:00:46 by jmarinho          #+#    #+#             */
/*   Updated: 2024/01/25 17:24:12 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
    this->type = "default";
}

Weapon::Weapon(std::string weaponType)
{
    this->type = weaponType;
}

Weapon::~Weapon() {
    
}

const std::string Weapon::getType() const {
    return(type);
}

void Weapon::setType(const std::string &newType) {
    type = newType;
}
