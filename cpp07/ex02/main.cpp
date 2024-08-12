/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:12:42 by jmarinho          #+#    #+#             */
/*   Updated: 2024/08/12 15:05:19 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<std::string> c;
	Array<int> a(1);
	
	std::cout << "c array size is " << c.size() << std::endl;


	a[0] = 42;
	std::cout << "a array value is " << a[0] << std::endl;
	std::cout << "a array size is " << a.size() << std::endl;

	Array<int> b(1);

	b = a;
	std::cout << "b array value b4 changes is " << b[0] << std::endl;

	a[0] = 100;
	b[0] = 21;
	std::cout << "a array value after changes is " << a[0] << std::endl;
	std::cout << "b array value after changes is " << b[0] << std::endl;
		
	Array<char> d(6);

	d[0] = 'a';
	d[1] = 'b';
	d[2] = 'c';
	d[3] = 'd';
	d[4] = 'e';
	d[5] = '\0';

	for (int k = 0; k < 5; k++)
		std::cout << "d[" << k << "] array value is " << d[k] << std::endl;
	std::cout << "d array size is " << d.size() << std::endl;

	try {
        Array<int> count(5);
 
        for (unsigned int i = 0; i < count.size(); i++) {
            count[i] = i * 10;
        }

        for (unsigned int i = 0; i < count.size(); i++) {
            std::cout << "Element at index " << i << ": " << count[i] << std::endl;
        }

        std::cout << "Attempting to access an out-of-bounds index..." << std::endl;
        count[10] = 100;

    } catch (const std::exception &e) {
		
        std::cerr << e.what() << std::endl;
    }
}
