/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:14:42 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/08 14:56:54 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(){

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

}