/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:21:04 by jmarinho          #+#    #+#             */
/*   Updated: 2024/07/26 17:05:52 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), is_signed(false), grade_to_sign(150), grade_to_execute(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm default destructor called" << std::endl;
}

AForm::AForm(const AForm &other) : name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute) {
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm::AForm(const std::string new_name, bool new_is_signed, const int new_grade_to_sign, const int new_grade_to_execute)
	: name(new_name), is_signed(new_is_signed), grade_to_sign(new_grade_to_sign), grade_to_execute(new_grade_to_execute)
{
    if (new_grade_to_sign < 1 || new_grade_to_execute < 1)
        throw GradeTooHighException();
    if (new_grade_to_sign > 150 || new_grade_to_execute > 150)
        throw GradeTooLowException();

    std::cout << "AForm param constructor called" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Exeption throwed: Grade High Low!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Exeption throwed: Grade Too Low!";
}

AForm& AForm::operator=(const AForm &other)
{
    if (this != &other)
	{
        const_cast<std::string&>(name) = other.name;
        this->is_signed = other.is_signed;
        const_cast<int&>(grade_to_sign) = other.grade_to_sign;
        const_cast<int&>(grade_to_execute) = other.grade_to_execute;
        
		std::cout << "AForm copy assignment operator called" << std::endl;
	}
	return *this;
}

std::ostream& operator<<(std::ostream &out, const AForm &form) {
    
    out << "AForm name is " << form.getName() << std::endl;
    if (form.getIs_Signed() == 0)
        out << "AForm is_signed status is false" << std::endl;
    else
        out << "AForm is_signed status is true" << std::endl;
    out << "AForm grade to sign is " << form.getGrade_To_Sign() << std::endl;
    out << "AForm grade to execute is " << form.getGrade_To_Execute() << std::endl;
	
    return out;
}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getIs_Signed() const
{
    return this->is_signed;
}

int AForm::getGrade_To_Sign() const
{
    return this->grade_to_sign;
}

int AForm:: getGrade_To_Execute() const
{
    return this->grade_to_execute;
}

void    AForm::beSigned(Bureaucrat *bureaucrat)
{
    if (bureaucrat->getGrade() > this->grade_to_sign)
        throw AForm::GradeTooLowException();
    this->is_signed = true;
	bureaucrat->signForm(this);
}

 void   AForm::execute(Bureaucrat const & executor) const {

        if (this->getIs_Signed() == true)
        {
            if (this->getGrade_To_Execute() >= executor.getGrade())
                this->Class_Executer("target");
            else
                throw AForm::GradeTooLowException();
        }
 }
