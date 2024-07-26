/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:07:02 by jmarinho          #+#    #+#             */
/*   Updated: 2024/07/26 17:11:58 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shub_Form", false, 145, 137) {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm default destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other)
    {
        target = other.target;
    }
    std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    return*this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string new_target) : target(new_target) {
    std::cout << new_target << " ShrubberyCreationForm param constructor called" << std::endl;
}

void    ShrubberyCreationForm::Class_Executer(std::string target) const {
    
    std::string tree = 
    
        "      /_-_\\\n"
        "    /~~   ~~\\\n"
        " /~~         ~~\\\n"
        "{               }\n"
        " \\  _-     -_  /\n"
        "   ~   \\ //  ~\n"
        "_- -   | | _- _\n"
        "  _ -  | |   -_\n"
        "      // \\\n";

    
    std::ofstream file((target + "_shrubbery").c_str());
    if (file.is_open())
    {
        file << tree;
        file.close();
        std::cout << "File " << target + "_shrubbery" << " created successfully." << std::endl;
    }
    else
        std::cerr << "Unable to open file: " << target + "_shrubbery" << std::endl;
}
