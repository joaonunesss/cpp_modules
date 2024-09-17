/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:52:39 by jmarinho          #+#    #+#             */
/*   Updated: 2024/09/17 11:45:46 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP  
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

typedef unsigned long uintptr_t;

class Serializer {
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data* 		deserialize(uintptr_t raw);
		
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &other);
		Serializer&operator=(const Serializer &other);
};
	

#endif

