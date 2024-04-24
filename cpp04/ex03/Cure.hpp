/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:25:51 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/22 17:42:07 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
    
    public:
        Cure();
        ~Cure();
        Cure(const Cure &other);
        Cure& operator=(const Cure &other);

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif
