/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:27:39 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/15 13:33:41 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
    
    public:
        Brain();
        Brain(std::string other_type);
        ~Brain();
        Brain(const Brain &other);
        Brain&operator=(const Brain &other);

        std::string ideas[100];

};

#endif