/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:22:05 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/18 14:48:17 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTrap_HPP
#define ScavTrap_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

    public:
        ScavTrap(std::string set_name);
        ~ScavTrap();
        ScavTrap( ScavTrap const &other);


        void attack(const std::string& target);
        void guardGate();
    
    protected:
    
};

#endif