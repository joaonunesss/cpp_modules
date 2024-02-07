/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:58:50 by jmarinho          #+#    #+#             */
/*   Updated: 2024/02/07 10:41:08 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap claptrap("Joe");
    ClapTrap claptrap2(claptrap);
    
    claptrap.attack("target");
    claptrap.takeDamage(5);
    claptrap.beRepaired(5);
    
    return 0; 
}