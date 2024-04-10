/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:43:44 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/09 11:51:48 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap{
    
    public:
        DiamondTrap();
        DiamondTrap(std::string other_name);
        ~DiamondTrap();
        DiamondTrap(const DiamondTrap &other);
        DiamondTrap&operator=(const DiamondTrap& other);

        void attack(const std::string& target);

        void whoAmI();

    private:
        std::string name;      
};

#endif