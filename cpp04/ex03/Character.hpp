/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:27:37 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/23 13:56:46 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
    
    public:
        Character();
        ~Character();
        Character(const std::string &other_name);
        Character(const Character &other);
        Character& operator=(const Character &other);

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        
    private:
        AMateria *inventory[4];
        AMateria *unequip_list[99];
        std::string name;
};

#endif