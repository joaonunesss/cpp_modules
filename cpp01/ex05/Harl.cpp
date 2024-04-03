/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:57:34 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/02 14:47:05 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain( std::string level ){

    std::string str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    
    void (Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    while (str[i] != level && i <= 4)
        i++;
    if (i > 3)
    {
        std::cout << "Invalid level" << std::endl;
        return ;
    }
        
    (this->*ptr[i])();

}

void Harl::debug( void ){
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ){
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ){
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."  << std::endl;
}

void Harl::error( void ){
    std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}
