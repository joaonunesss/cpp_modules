/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:58:50 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/18 15:08:38 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void )
{
    ScavTrap scavtrap("Bill");
    ScavTrap scavtrap2(scavtrap);

    scavtrap.attack("target");
    scavtrap.guardGate();
    
    return 0; 
}