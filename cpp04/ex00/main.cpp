/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:59:22 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/30 11:52:28 by jmarinho         ###   ########.fr       */
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
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    std::cout << RESET;

    delete meta;
    delete j;
    delete i;
    
    Animal meta00;
    std::cout << std::endl;
    Dog dog00;
    std::cout << std::endl;
    Cat cat00;

    std::cout << std::endl;

    Animal meta01(meta00);
    std::cout << std::endl;
    Dog dog01(dog00);
    std::cout << std::endl;
    Cat cat01(cat00);
    
    std::cout << std::endl;

    Animal meta02("meta02");
    std::cout << std::endl;
    Dog dog02("dog02");
    std::cout << std::endl;
    Cat cat02("cat02");
    
    std::cout << std::endl;

    std::cout  << "meta02 type is: ";
    std::cout << meta02.getType() << " " << std::endl;
    std::cout << "dog02 type is: ";
    std::cout << dog02.getType() << " " << std::endl;
    std::cout << "cat02 type is: ";
    std::cout << cat02.getType() << " "  << std::endl;

    std::cout << std::endl;

    std::cout << RED << "WrongAnimal and WrongCat tests beginning..." << RESET << std::endl;

    const WrongAnimal* wa = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();

    std::cout << "wa type is: ";
    std::cout << wa->getType() << " " << std::endl;
    std::cout << "wc type is: ";
    std::cout << wc->getType() << " " << RESET << std::endl;
    
    std::cout << RED;
    wc->makeSound();
    wa->makeSound();
    std::cout << RESET;
    
    std::cout << YELLOW << std::endl;
    WrongCat TheCat;
    TheCat.makeSound();
    std::cout << RESET << std::endl;

    delete wa;
    delete wc;

    WrongAnimal wa00;
    std::cout << std::endl;
    WrongCat wc00;

    std::cout << std::endl;

    WrongAnimal wa01(wa00);
    std::cout << std::endl;
    WrongCat wc01(wc00);
    
    std::cout << std::endl;

    WrongAnimal wa02("WrongAnimal02");
    std::cout << std::endl;
    WrongCat wc02("WrongCat02");
    
    std::cout << std::endl;

    std::cout << "wa02 type is: ";
    std::cout << wa02.getType() << " " << std::endl;
    std::cout << "wc02 type is: ";
    std::cout << wc02.getType() << " " << std::endl;

    std::cout << std::endl;

    return 0;
}
