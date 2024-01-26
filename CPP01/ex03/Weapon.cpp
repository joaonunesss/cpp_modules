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

Weapon::Weapon(){
}

Weapon::Weapon(std::string weaponType)
{
    this->type = weaponType;
}

Weapon::~Weapon(){
}

const std::string Weapon::getType() {
    return(this->type);
}

void Weapon::setType(std::string newType) {
    type = newType;
}
