/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:03:42 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/12 12:03:48 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {

    public:
        WrongAnimal();
        WrongAnimal(std::string other_type);
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
        WrongAnimal&operator=(const WrongAnimal &other);

        const std::string getType() const;
        void makeSound() const;
        
    protected:
        std::string type;
};

#endif