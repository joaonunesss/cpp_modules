/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:27:15 by jmarinho          #+#    #+#             */
/*   Updated: 2024/01/25 17:21:16 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon{
    
    public:
        Weapon();
        Weapon(std::string weaponType);
        ~Weapon();
        const std::string getType();
        void setType(std::string newType);
        
    private:
        std::string type;

};

#endif
