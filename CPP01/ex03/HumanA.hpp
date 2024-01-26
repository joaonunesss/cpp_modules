/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:33:09 by jmarinho          #+#    #+#             */
/*   Updated: 2024/01/25 17:27:03 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {
    
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void attack() const;
    
    private:
        std::string nameA;
        Weapon &WeaponA;
};

#endif