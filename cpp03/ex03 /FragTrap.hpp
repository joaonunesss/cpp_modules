/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:03:28 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/09 12:32:11 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

    public:
        FragTrap();
        ~FragTrap();
        FragTrap(std::string other_name); 
        FragTrap(FragTrap const &other);
        FragTrap&operator=(const FragTrap& other);

        void attack(const std::string& target);
        
        void highFivesGuys(void);
    
    protected:
    
};

#endif