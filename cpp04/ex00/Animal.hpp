/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:15:12 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/30 11:54:56 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {

    public:
        Animal();
        Animal(std::string other_type);
        virtual ~Animal();
        Animal(const Animal &other);
        Animal&operator=(const Animal &other);

        const std::string getType() const;
        virtual void makeSound() const;
        
    protected:
        std::string type;
};

#endif