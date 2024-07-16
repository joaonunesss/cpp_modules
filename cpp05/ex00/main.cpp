/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:51:24 by jmarinho          #+#    #+#             */
/*   Updated: 2024/07/16 14:20:14 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureucrat.hpp"

int main()
{
    Bureucrat *def = new Bureucrat;
    
    std::cout << "Def Bureucrat name is " << def->getName() << " and grade is " << def->getGrade() << std::endl;
    delete (def);

    Bureucrat bur("Mila", 1);
    std::cout << "Bur Bureucrat name is " << bur.getName() << " and grade is " << bur.getGrade() << std::endl;


    try {
        Bureucrat low("low", 151);
    } catch (const Bureucrat::GradeTooHighException &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    } catch (const Bureucrat::GradeTooLowException &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureucrat high("high", -1);
    } catch (const Bureucrat::GradeTooHighException &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    } catch (const Bureucrat::GradeTooLowException &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}
