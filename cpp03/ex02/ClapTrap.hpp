/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:24:21 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/18 15:05:53 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <iostream>

class ClapTrap{

    public:
        ClapTrap(std::string set_name);
        ~ClapTrap();
        ClapTrap( ClapTrap const &other);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    protected:
        std::string new_name;
        int hitpoints = 100;
        int energyPoints = 100;
        int attackDamage = 30;
    
};

#endif
