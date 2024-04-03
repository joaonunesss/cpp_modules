/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:42:11 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/27 15:50:15 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
    
}

Zombie::Zombie(std::string name){
    
    name = name;
}

Zombie::~Zombie(){
    
    std::cout << name << " is destroyed!" << std::endl;
}

void Zombie::announce(){
    
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name){
    
    this->name = name;
}