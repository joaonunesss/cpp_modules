/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:31:42 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/23 15:47:06 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource default constructor called!" << std::endl;
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource default destructor called!" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if(materias[i])
        {
            delete materias[i];
            materias[i] = NULL;
            std::cout << RED << "Materia has been deleted!" << RESET << std::endl;
        }
    } 
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    std::cout << "MateriaSource copy constructor called!" << std::endl;
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
    *this = other;
}
MateriaSource& MateriaSource::operator=(const MateriaSource &other) {
    std::cout << "MateriaSource copy operator called!" << std::endl;
    type = other.type;
    for (int i = 0; i < 4; i++)
    {
        if (materias[i])
            delete materias[i];
    }
    for (int i = 0; i < 4; i++)
    {
        if (other.materias[i] != NULL)
            materias[i] = other.materias[i]->clone();   
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* materia) {
    
   int i = 0;
    
    while (i < 4)
    {
        if (materias[i] == NULL)
        {    
            std::cout << GREEN << materia->getType() << RESET;
            std::cout << " learned!" << std::endl;
            materias[i] = materia;
            return ;
        }
        i++;
    }
    if (i == 4)
        std::cout << "No, no! Maximum materias learned!" << std::endl;    
}

AMateria* MateriaSource::createMateria(std::string const &type) {


    if (type == "ice" || type == "cure")
    {
        for (int i = 0; i < 4; i++)
        {
            if (!materias[i])
            {
                std::cout << "Materia DOES NOT exist!" << std::endl;
                return 0;
            }
            if (materias[i]->getType() == type)
            {
                std::cout << GREEN << type << RESET;
                std::cout << " Materia created!" << std::endl;
                return materias[i]->clone();
            }
        }
    }
    std::cout << "Materia unknown and NOT created!" << std::endl;
    return 0;
}