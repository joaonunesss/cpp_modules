/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:59:04 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/19 14:29:56 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    
    public:
        Animal();
        virtual ~Animal();
        Animal(Animal &other);
        virtual void makeSound() const;
        std::string getType() const;
    
    protected:
        std::string type;
};

#endif