/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:49:07 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/27 17:12:35 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name )
{
     Zombie *horde = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        horde[i].set_name(name);
        horde[i].announce();
    }

    return (horde);
}