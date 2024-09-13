/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:07:02 by jmarinho          #+#    #+#             */
/*   Updated: 2024/09/03 12:02:10 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robot_Form", false, 72, 45) {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm default destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)  : AForm (other), target(other.target) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
    if (this != &other)
    {
        target = other.target;
    }
    return*this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string new_target) : target(new_target) {
    std::cout << "RobotomyRequestForm param constructor called" << std::endl;
}

void    RobotomyRequestForm::Class_Executer(std::string target) const {

    std::srand(time(0));
    int randomNumber = rand();

    std::cout << "Whirr-whirr-whirr! Bzzzzt! Bzzzzt! Bzzzzt!" << std::endl;
    
    if (randomNumber % 2 == 0)
        std::cout << target << " has been robotomized" << std::endl;
    else
        std::cout << target << " robotomy has failed" << std::endl;
}
