/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:54:13 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/27 15:23:34 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *myZ; //deep copy
    
    myZ = newZombie("Manel");
    myZ->announce();
    delete(myZ);
    
    randomChump("Zeca"); //shallow copy
}