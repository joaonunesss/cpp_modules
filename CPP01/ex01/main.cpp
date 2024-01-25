/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:12:58 by jmarinho          #+#    #+#             */
/*   Updated: 2024/01/25 14:27:56 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 8;
    Zombie *horde = zombieHorde(N, "Quim");

    for (int i = 0; i < N; i++)
    {
        std::cout << "Zombie " << i + 1  <<std::endl;
        horde[i].announce();
    }

    delete[] horde;
}