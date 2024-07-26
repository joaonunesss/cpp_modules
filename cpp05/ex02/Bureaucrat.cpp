/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:39:44 by jmarinho          #+#    #+#             */
/*   Updated: 2024/07/17 12:32:47 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(100) {
	std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Default destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
	{
		const_cast<std::string&>(name) = other.name;
		grade = other.grade;
		std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
	}
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bur) {
    os << "Bureaucrat: " << bur.name << ", Grade: " << bur.grade << std::endl;
	
    return os;
}
Bureaucrat::Bureaucrat(const std::string new_name, int new_grade) : name(new_name) {
	
	if (new_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (new_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	grade = new_grade;
	std::cout << "Bureaucrat Param constructor called" << std::endl;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade Too Low!";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade Too High!";
}

const	std::string Bureaucrat::getName() const {
	return this->name;
}

int		Bureaucrat::getGrade() const {
	return this->grade;
}

void	Bureaucrat::incrementGrade() {
	if (grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void	Bureaucrat::decrementGrade() {
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

void	Bureaucrat::signForm(AForm *form)
{
    if (form->getIs_Signed() == true)
        std::cout << this->name << " signed " << form->getName() << std::endl;
	else if (this->grade > form->getGrade_To_Sign())
	{
		std::cout << this->name << " couldn't sign " << form->getName() << " because Bureaucrat grade is to low!" << std::endl;
		std::cout << "Grade needed to sign is " << form->getGrade_To_Sign() << " and " << this->name << " grade is " << this->grade << std::endl;
	}
}

void    Bureaucrat::executeForm(AForm const & form) {
	
	if (form.getIs_Signed() == true)
	{
		if (form.getGrade_To_Execute() >= this->getGrade())
		{
			std::cout << this->getName() << " executed " << form.getName() << std::endl;
			form.execute(*this);
		}
		else
			throw AForm::GradeTooLowException();
	}
	else
		std::cout << "Error executing form" << std::endl;
}