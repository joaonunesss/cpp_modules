/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:15:12 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/16 11:49:52 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_ANIMAL_HPP
#define A_ANIMAL_HPP

#include <iostream>

class A_Animal {

    public:
        A_Animal();
        A_Animal(std::string other_type);
        virtual ~A_Animal();
        A_Animal(const A_Animal &other);
        A_Animal&operator=(const A_Animal &other);

        const std::string getType() const;
        virtual void makeSound() const = 0;
        
    protected:
        std::string type;
};

#endif