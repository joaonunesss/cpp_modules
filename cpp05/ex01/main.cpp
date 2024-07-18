/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:51:24 by jmarinho          #+#    #+#             */
/*   Updated: 2024/07/18 14:49:53 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Form        *new_form = new Form;
    Form        form("B3", false, 10, 10);
    
    std::cout << std::endl;
    std::cout << form << std::endl;

    try {
        Form low("low", false, 151, 151);  //This will throw GradeTooLowException
    } catch (const Form::GradeTooLowException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;;
    } catch (const Form::GradeTooHighException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Form high("high", false, 0, 0);  //This will throw GradeTooHighException
    } catch (const Form::GradeTooLowException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    } catch (const Form::GradeTooHighException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
   
    std::cout << std::endl;

    Form        sig("A2024/55", false, 1, 1);
    Bureaucrat   def("Americo", 150);
    Bureaucrat   def2("Joaquim", 1);

    std::cout << std::endl;
    
    std::cout << "Bureaucrat with grade 150 tryng to sign form" << std::endl;
    try {
        sig.beSigned(&def); //This will throw GradeTooLowException
    } catch (const Form::GradeTooLowException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;;
    } catch (const Form::GradeTooHighException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
   
    std::cout << "Bureaucrat with grade 1 tryng to sign form" << std::endl;
    try {
        sig.beSigned(&def2); //This will be successfull
    } catch (const Form::GradeTooLowException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;;
    } catch (const Form::GradeTooHighException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Bureaucrat with grade 150 trying to sign a form with grade_to_sing 10 " << std::endl;
    std::cout << std::endl;
    try {
         def.signForm(&form); //This will not be successfull
    } catch (const Form::GradeTooLowException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;;
    } catch (const Form::GradeTooHighException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    
    std::cout << "Bureaucrat with grade 1 trying to sign a form with grade_to_sing 10 " << std::endl;
    std::cout << std::endl;
    std::cout << "def2 sign status " << form.getIs_Signed() << std::endl;
    try {
         def2.signForm(&form); //This will be successfull
    } catch (const Form::GradeTooLowException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;;
    } catch (const Form::GradeTooHighException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << "def2 sign status " << form.getIs_Signed() << std::endl;
    std::cout << std::endl;

    delete (new_form);
}
