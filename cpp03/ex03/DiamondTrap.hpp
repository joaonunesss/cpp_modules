/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:12:05 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/18 16:28:19 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DiamondTrap_HPP
#define DiamondTrap_HPP

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

    public:
        DiamondTrap(std::string set_name);
        ~DiamondTrap();
        DiamondTrap( DiamondTrap const &other);

        /*void attack(const std::string& target);*/
        void printpoints();
        using ScavTrap::attack;
        void whoAmI();
    
    protected:
        std::string new_name;
        void set_attackfunction();
    
};

#endif