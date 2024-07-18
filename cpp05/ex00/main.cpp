/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:51:24 by jmarinho          #+#    #+#             */
/*   Updated: 2024/07/18 14:36:00 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat *def = new Bureaucrat;
    
    std::cout << "Def Bureaucrat name is " << def->getName() << " and grade is " << def->getGrade() << std::endl;
    delete (def);

    Bureaucrat bur("Mila", 1);
    std::cout << "Bur Bureaucrat name is " << bur.getName() << " and grade is " << bur.getGrade() << std::endl;

    try {
        Bureaucrat low("low", 151); //Grade too low
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat high("high", -1); //Grade to high
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    bur.decrementGrade();
    std::cout << bur.getName() << " grade after decrement is " << bur.getGrade() << std::endl;
    bur.incrementGrade();
    std::cout << bur.getName() << " grade after increment is " << bur.getGrade() << std::endl;

    try {
         bur.incrementGrade(); //Increment makes grade to high
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << bur;
}
