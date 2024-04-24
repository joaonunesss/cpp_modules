/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:59:22 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/15 17:39:51 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::string RED = "\033[0;31m";
    std::string GREEN = "\033[0;32m";
    std::string YELLOW = "\033[0;33m";
    std::string RESET = "\033[0m";

    const A_Animal* j = new Dog();
    const A_Animal* i = new Cat();
    
    std::cout << std::endl;
    std::cout << "j type is: ";
    std::cout << j->getType() << " " << std::endl;
    std::cout << "i type is: ";
    std::cout << i->getType() << " " << std::endl;
    
    std::cout << std::endl;
    std::cout << GREEN;
    i->makeSound();
    j->makeSound();
    std::cout << RESET;

    std::cout << std::endl;
    delete j;
    delete i;

    //A_Animal animal;

}
