/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:49:28 by jmarinho          #+#    #+#             */
/*   Updated: 2024/02/05 11:08:08 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    return;
}

Harl::~Harl()
{
    return;
}

void Harl::debug(void){
            std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
        }
        
void Harl::info(void){
            std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
        }

void Harl::warning(void){
            std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
        }

void Harl::error(void){
            std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
        }

void Harl::complain( std::string level ){
    
    std::map<std::string, std::function<void()>> levelMap = {

        {"DEBUG", std::bind(&Harl::debug, this)},
        {"INFO", std::bind(&Harl::info, this)},
        {"WARNING", std::bind(&Harl::warning, this)},
        {"ERROR", std::bind(&Harl::error, this)}
    };

    auto iterator = levelMap.find(level);
    if (iterator != levelMap.end())
        iterator->second();
    else
        std::cout << "Unknown level: " << level << std::endl;
}