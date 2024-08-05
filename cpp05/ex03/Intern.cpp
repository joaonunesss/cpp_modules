/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:27:28 by jmarinho          #+#    #+#             */
/*   Updated: 2024/07/30 12:15:38 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern() {
    std::cout << "Intern default destructor called" << std::endl;
}

Intern::Intern(Intern &other) {
    *this = other;
    std::cout << "Intern Copy constructor called" << std::endl;
}

Intern& Intern::operator=(Intern &other) {
    std::cout << "Intern Assignement Operator called" << std::endl;
    (void) other;
    return *this;
}

AForm *Intern::makeForm(std::string form_name, std::string form_target) {

    AForm *result = NULL;
    AForm *forms[] = {new ShrubberyCreationForm(form_target), new RobotomyRequestForm(form_target), new PresidentialPardonForm(form_target)};
    
    std::string formsArray[3] = {"Shrub_Form", "Robot_Form", "Pres_Form"};

    for (int i = 0; i < 3; i++)
        {
            if (formsArray[i] == form_name)
            {
                std::cout << "Intern creates " << form_name << std::endl;
                result = forms[i];
                delete (forms[i]);
            }
            else
                delete (forms[i]);
        }
        if (result == NULL)
            std::cout << "Intern could not create " << form_name << std::endl;

        return (result);
}
