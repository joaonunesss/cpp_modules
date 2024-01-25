/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:33 by jmarinho          #+#    #+#             */
/*   Updated: 2024/01/25 13:45:28 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream> 

class Zombie {
    
    public:
    
    Zombie(std::string name);
    ~Zombie();
    void announce(void);
    
    private:

    std::string name;
};

    Zombie *newZombie(std::string name);
    void randomChump(std::string name);

#endif