/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:21:04 by jmarinho          #+#    #+#             */
/*   Updated: 2024/07/18 14:49:20 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), is_signed(false), grade_to_sign(150), grade_to_execute(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form default destructor called" << std::endl;
}

Form::Form(const Form &other) : name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute) {
    std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(const std::string new_name, bool new_is_signed, const int new_grade_to_sign, const int new_grade_to_execute)
	: name(new_name), is_signed(new_is_signed), grade_to_sign(new_grade_to_sign), grade_to_execute(new_grade_to_execute)
{
    if (new_grade_to_sign < 1 || new_grade_to_execute < 1)
        throw GradeTooHighException();
    if (new_grade_to_sign > 150 || new_grade_to_execute > 150)
        throw GradeTooLowException();

    std::cout << "Form param constructor called" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade High Low!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade Too Low!";
}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
	{
        const_cast<std::string&>(name) = other.name;
        this->is_signed = other.is_signed;
        const_cast<int&>(grade_to_sign) = other.grade_to_sign;
        const_cast<int&>(grade_to_execute) = other.grade_to_execute;
        
		std::cout << "Form copy assignment operator called" << std::endl;
	}
	return *this;
}

std::ostream& operator<<(std::ostream &out, const Form &form) {
    
    out << "Form name is " << form.getName() << std::endl;
    if (form.getIs_Signed() == 0)
        out << "Form is_signed status is false" << std::endl;
    else
        out << "Form is_signed status is true" << std::endl;
    out << "Form grade to sign is " << form.getGrade_To_Sign() << std::endl;
    out << "Form grade to execute is " << form.getGrade_To_Execute() << std::endl;
	
    return out;
}

std::string Form::getName() const
{
    return this->name;
}

bool Form::getIs_Signed() const
{
    return this->is_signed;
}

int Form::getGrade_To_Sign() const
{
    return this->grade_to_sign;
}

int Form:: getGrade_To_Execute() const
{
    return this->grade_to_execute;
}

void    Form::beSigned(Bureaucrat *bureaucrat)
{
    if (bureaucrat->getGrade() > this->grade_to_sign)
        throw Form::GradeTooLowException();
    this->is_signed = true;
	bureaucrat->signForm(this);
}
