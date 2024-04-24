/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:33:06 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/15 13:33:26 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called!" << std::endl;
    for(int i = 0; i < 100; i++)
        ideas[i] = "empty thoughts";
}

Brain::~Brain() {
    std::cout << "Brain default destructor called!" << std::endl;
}

Brain::Brain(const Brain &other) {
    std::cout << "Brain copy constructor called!" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain &other) {
    std::cout << "Brain copy assignment operator called!" << std::endl;
    return *this;
}
