/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:03:28 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/18 16:26:28 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
#define FragTrap_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

    public:
        FragTrap(std::string set_name);
        ~FragTrap();
        FragTrap( FragTrap const &other);

        void attack(const std::string& target);
        void highFivesGuys(void);
    
    protected:

};

#endif