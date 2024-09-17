/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:12:42 by jmarinho          #+#    #+#             */
/*   Updated: 2024/09/17 14:34:57 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{    
	std::string int_array[] = {"a", "b", "c"};

	iter(int_array, 3, &print_elements_of_array<std::string>);
	
	return 0;
}
