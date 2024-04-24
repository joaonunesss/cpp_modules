/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:22:10 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/22 17:42:10 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
    
    public:
        Ice();
        ~Ice();
        Ice(const Ice &other);
        Ice& operator=(const Ice &other);

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif