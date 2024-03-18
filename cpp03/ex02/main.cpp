/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:58:50 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/18 15:10:31 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main( void )
{
    FragTrap fragtrap("Jake");
    FragTrap fragtrap2(fragtrap);

    fragtrap.attack("target");
    fragtrap.highFivesGuys();
    
    return 0; 
}