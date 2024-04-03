/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:30:46 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/02 14:55:19 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(){

    Harl harl;
    std::string level;
    
    std::cout << "Enter level." << std::endl;
    std::cout <<  "DEBUG, INFO, WARNING, ERROR" << std::endl;
    std::cin >> level;

    harl.complain(level);
}