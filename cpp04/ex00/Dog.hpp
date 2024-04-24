/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:15:12 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/16 11:52:18 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

    public:
        Dog();
        Dog(std::string other_type);
        ~Dog();
        Dog(const Dog &other);
        Dog&operator=(const Dog &other);

        void makeSound() const;
};

#endif