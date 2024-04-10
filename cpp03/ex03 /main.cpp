/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:14:42 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/09 12:56:06 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(){

    /*std::cout << "ClapTrap beggining..." << std::endl;

    ClapTrap Trap0;
    ClapTrap Trap1("Bob");    
    ClapTrap Trap2(Trap1);

    std::cout << std::endl;

    Trap0.attack("Manel");
    Trap0.takeDamage(15);
    Trap0.beRepaired(1);

    Trap0.attack("Manel");

    std::cout << std::endl;
    
    Trap2.attack("Quim");
    Trap2.takeDamage(5);
    Trap2.beRepaired(5);

    Trap2.attack("Quim");

    std::cout << std::endl;
    std::cout << "ScavTrap beggining..." << std::endl;

    ScavTrap Scav0;
    ScavTrap Scav1("Jim");
    ScavTrap Scav2(Scav1);

    std::cout << std::endl;

    Scav0.attack("Manel");
    Scav0.takeDamage(150);
    Scav0.beRepaired(1);

    Scav0.attack("Manel");

    Scav0.guardGate();

    std::cout << std::endl;
    
    Scav2.attack("Quim");
    Scav2.takeDamage(5);
    Scav2.beRepaired(5);

    Scav2.attack("Quim");

    Scav2.guardGate();

    std::cout << std::endl;
    std::cout << "FragTrap beggining..." << std::endl;

    FragTrap Frag0;
    FragTrap Frag1("Kleber");
    FragTrap Frag2(Frag1);

    std::cout << std::endl;

    Frag0.attack("Manel");
    Frag0.takeDamage(150);
    Frag0.beRepaired(1);

    Frag0.attack("Manel");

    Frag0.highFivesGuys();

    std::cout << std::endl;
    
    Frag2.attack("Quim");
    Frag2.takeDamage(5);
    Frag2.beRepaired(5);

    Frag2.attack("Quim");

    Frag2.highFivesGuys();

    std::cout << std::endl;*/
    std::cout << "DiamondTrap beggining..." << std::endl;
    
    DiamondTrap Diamond0;
    DiamondTrap Diamond1("Fernando");
    DiamondTrap Diamond2(Diamond1);

    std::cout << std::endl;

    Diamond0.attack("Manel");
    Diamond0.takeDamage(150);
    Diamond0.beRepaired(1);

    Diamond0.attack("Manel");

    Diamond0.whoAmI();

    std::cout << std::endl;
    
    Diamond2.attack("Quim");
    Diamond2.takeDamage(5);
    Diamond2.beRepaired(5);

    Diamond2.attack("Quim");

    Diamond2.whoAmI();

    std::cout << std::endl;
    

}