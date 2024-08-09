/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:12:42 by jmarinho          #+#    #+#             */
/*   Updated: 2024/08/09 14:47:40 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[36m"
# define RESET "\033[37m"

int main()
{    
    Data *data = new Data;
	Serializer ser;


	//WITH INT
	data->x = 42;
	data->str = "string";

    std::cout << GREEN;
    std::cout << "Data value is: " << data->x << std::endl;
    std::cout << "Data string is: " << data->str << std::endl << std::endl;
    
    std::cout << BLUE;
    uintptr_t uint_ptr = ser.serialize(data);
    std::cout << "Serialized uintptr_t is: " << uint_ptr << std::endl << std::endl;
    
    std::cout << YELLOW;
	Data* data2 = ser.deserialize(uint_ptr);
    std::cout << "Deserialize data value is: " << data2->x << std::endl;
	std::cout << "Deserialize data string is: " << data2->str << std::endl;

	delete data;
	
	std::cout << RESET;
}
