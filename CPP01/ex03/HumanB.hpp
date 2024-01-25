/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:37:08 by jmarinho          #+#    #+#             */
/*   Updated: 2024/01/25 17:27:11 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {
    
    public:
        HumanB();
        HumanB(std::string name);
        ~HumanB();
        void attack();
        void setWeapon(const Weapon &weapon);
    
    private:
        std::string nameB;
        Weapon *WeaponB;
};

#endif