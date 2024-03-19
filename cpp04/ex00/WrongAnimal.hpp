/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:34:34 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/19 14:38:40 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
    
    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(WrongAnimal &other);
        void makeSound() const;
        std::string getType() const;
    
    protected:
        std::string type;
};

#endif