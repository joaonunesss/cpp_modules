/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:59:22 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/23 16:42:51 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");//create new from name constructor
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    tmp = src->createMateria("fire");//cannot create fire
    
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    me->unequip(0);
    me->unequip(1);

    me->use(0, *bob);//materia not equiped
    me->use(1, *bob);//materia not equiped

    delete bob;
    delete me;
    delete src;
    
    IMateriaSource* src01 = new MateriaSource();
    AMateria* tmp01;
    
    src01->learnMateria(new Ice());
    tmp01 = src01->createMateria("ice");
    
    Character joao;
    ICharacter* you = new Character(joao);//create new from copy constructor

    you->equip(tmp01);
    you->equip(tmp01);//trying to equip what is already equiped  
    you->unequip(0);
    
    you->use(10, *you);//index does not exist
    you->unequip(10);//index does not exist
    
    delete you;
    delete src01;

    return 0;
}
