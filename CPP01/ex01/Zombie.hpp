/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:33 by jmarinho          #+#    #+#             */
/*   Updated: 2024/01/25 14:25:46 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream> 

class Zombie {
    
    public:
    
    Zombie(std::string name);
    Zombie();
    ~Zombie();
    void announce(void);
    void setname(std::string name);
    
    private:

    std::string name;
};

Zombie *zombieHorde( int N, std::string name );

#endif