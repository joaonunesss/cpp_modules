/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:15:12 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/15 14:50:51 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "A_Animal.hpp"
#include "Brain.hpp"

class Cat : public A_Animal {

    public:
        Cat();
        Cat(std::string other_type);
        ~Cat();
        Cat(const Cat &other);
        Cat&operator=(const Cat &other);

        void makeSound() const;

    private:
        Brain *cat_brain;
};

#endif