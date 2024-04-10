/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:14:44 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/08 17:29:06 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

  public:
    ClapTrap();
    ~ClapTrap();
    ClapTrap(std::string other_name);
    ClapTrap(const ClapTrap &other);
    ClapTrap&operator=(const ClapTrap &other);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

  protected:
    std::string name;
    int hit_points = 100;
    int energy_points = 100;
    int attack_damage = 30;
    
};

#endif