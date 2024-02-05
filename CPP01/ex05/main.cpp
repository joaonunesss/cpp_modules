/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:30:46 by jmarinho          #+#    #+#             */
/*   Updated: 2024/02/05 11:01:14 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    std::string level;
    Harl harl;
    
    std::cout << "Please introduce Harl level of complain: ";
    std::cin >> level;

    harl.complain(level);
}