/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:58:50 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/18 16:28:34 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void )
{
    DiamondTrap diamondtrap("Joel");
    DiamondTrap diamondtrap2(diamondtrap);

    diamondtrap.printpoints();
    diamondtrap.attack("target");
    diamondtrap.whoAmI();
    
    return 0; 
}