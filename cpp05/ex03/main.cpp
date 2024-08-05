/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:51:24 by jmarinho          #+#    #+#             */
/*   Updated: 2024/07/30 12:10:09 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* rrf;
    
    std::cout << YELLOW;
    rrf = someRandomIntern.makeForm("Shrub_Form", "joao1");
    
    std::cout << BLUE;
    rrf = someRandomIntern.makeForm("Robot_Form", "Bender");
    
    std::cout << GREEN;
    rrf = someRandomIntern.makeForm("Pres_Form", "joao3");

    std::cout << RESET;
}
