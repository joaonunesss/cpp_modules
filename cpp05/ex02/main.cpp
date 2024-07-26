/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:51:24 by jmarinho          #+#    #+#             */
/*   Updated: 2024/07/26 17:23:00 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat *boss = new Bureaucrat("boss", 1);
    Bureaucrat colab("Colab", 150);

    AForm *form = new PresidentialPardonForm;

    std::cout << YELLOW;

    form->beSigned(boss);

    std::cout << RESET << "Trying to execute form with boss" << std::endl;
    std::cout << YELLOW;
    try
    {
        boss->executeForm(*form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << RESET <<"Trying to execute form with colab" << std::endl;
    std::cout << YELLOW;
    try
    {
        colab.executeForm(*form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << BLUE;

    ShrubberyCreationForm sh_form;
    ShrubberyCreationForm sh_copy = sh_form;
    
    std::cout << sh_form;
    std::cout << sh_copy;
    
    sh_form.Class_Executer("Diodos");

    sh_form.beSigned(boss);
    std::cout << "sh_form grade to execute is " << sh_form.getGrade_To_Execute() << std::endl;
    
    std::cout << RESET << "Trying to execute sh_form with colab" << std::endl;
    std::cout << BLUE;
    try
    {
        sh_form.execute(colab);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << RED;

    RobotomyRequestForm rbt_form;
    RobotomyRequestForm rbt_copy = rbt_form;
    
    std::cout << rbt_form;
    std::cout << rbt_copy;
    
    rbt_form.Class_Executer("Cralos");

    rbt_form.beSigned(boss);
    std::cout << "rbt_form grade to execute is " << rbt_form.getGrade_To_Execute() << std::endl;

    std::cout << RESET << "Trying to execute rbt_form with colab" << std::endl;
    std::cout << RED;
    try
    {
        rbt_form.execute(colab);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << GREEN;

    PresidentialPardonForm pres_form;
    PresidentialPardonForm pres_copy = pres_form;
    
    std::cout << pres_form;
    std::cout << pres_copy;

    pres_form.Class_Executer("Rum");

    pres_form.beSigned(boss);
    std::cout << "pres_form grade to execute is " << pres_form.getGrade_To_Execute() << std::endl;  
    
    std::cout << RESET << "Trying to execute pres_form with colab" << std::endl;
    std::cout << GREEN;
    try
    {
        pres_form.execute(colab);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << RESET;

    delete(boss);    
}
