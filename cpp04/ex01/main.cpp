/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:59:22 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/30 12:02:21 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
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

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "j type is: ";
    std::cout << j->getType() << " " << std::endl;
    std::cout << "i type is: ";
    std::cout << i->getType() << " " << std::endl;
    
    std::cout << GREEN;
    j->makeSound();
    i->makeSound();
    meta->makeSound();
    std::cout << RESET;

    delete meta;
    delete j;
    delete i;

    std::cout << std::endl;
    std::cout << RED << "Array tests" << RESET << std::endl;

    Animal *animal_array[4];

    
    std::cout << RED << "/////////////DOG//////////" << RESET << std::endl;
    for (int i = 0; i < 2; i++)
        animal_array[i] = new Dog();
    std::cout << RED << "/////////////CAT//////////" << RESET << std::endl;
    for (int i = 2; i < 4; i++)
        animal_array[i] = new Cat();;
    std::cout << RED << "/////////////ANIMAL//////////" << RESET << std::endl;
    for (int i = 0; i < 4; i++)
        delete animal_array[i];

    std::cout << std::endl;
    std::cout << RED << "Cat tests" << RESET << std::endl;
    Cat cat00;
    Cat cat02(cat00);
    
    std::cout << std::endl;
    std::cout << RED << "Dog tests" << RESET << std::endl;
    Dog dog00;
    Dog dog02(dog00);

    std::cout << std::endl;
    std::cout << RED << "Deep copy tests" << RESET << std::endl;
    Dog basic;

    Dog tmp = basic;
}
