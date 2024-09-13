/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:07:02 by jmarinho          #+#    #+#             */
/*   Updated: 2024/09/03 12:01:20 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Pres_Form", false, 25, 5) {
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm default destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)  :AForm(other), target(other.target) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
    if (this != &other)
    {
        target = other.target;
    }
    return*this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string new_target) : target(new_target) {
    std::cout << "PresidentialPardonForm param constructor called" << std::endl;
}

void    PresidentialPardonForm::Class_Executer(std::string target) const {
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
