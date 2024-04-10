/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:15:45 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/09 12:32:04 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

public:
    ScavTrap();                      
    ~ScavTrap();                     
    ScavTrap(std::string other_name); 
    ScavTrap(const ScavTrap& other);
    ScavTrap&operator=(const ScavTrap& other);

    void attack(const std::string& target);
    
    void guardGate();
};

#endif
