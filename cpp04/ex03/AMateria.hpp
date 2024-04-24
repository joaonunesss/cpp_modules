/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:19:44 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/23 16:41:36 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

#define  RED "\033[0;31m"
#define  GREEN "\033[0;32m"
#define  YELLOW "\033[0;33m"
#define  RESET "\033[0m"

class ICharacter;

class AMateria
{
    protected:
        std::string type;
    
    public:
        AMateria();
        virtual ~AMateria();
        AMateria(std::string const &type);
        AMateria(const AMateria &other);
        AMateria&operator=(const AMateria &other);
        
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        
        virtual void use(ICharacter& target);
        
        int flag_equiped;
};

#endif