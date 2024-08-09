/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OtherClasses.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:02:58 by jmarinho          #+#    #+#             */
/*   Updated: 2024/08/09 16:15:43 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OtherClasses.hpp"

A::~A() {
	std::cout << "A destructor called" << std::endl;	
}

B::~B(){
	std::cout << "B destructor called" << std::endl;
}

C::~C(){
	std::cout << "C destructor called" << std::endl;
}