/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureucrat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:39:44 by jmarinho          #+#    #+#             */
/*   Updated: 2024/07/16 14:18:57 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureucrat.hpp"

Bureucrat::Bureucrat() : name("Default"), grade(100) {
	std::cout << "Default constructor called" << std::endl;
}

Bureucrat::~Bureucrat() {
	std::cout << "Default destructor called" << std::endl;
}

Bureucrat::Bureucrat(const Bureucrat &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Bureucrat& Bureucrat::operator=(const Bureucrat &other) {
	if (this != &other)
	{
		const_cast<std::string&>(name) = other.name;
		grade = other.grade;
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return *this;
}

Bureucrat::Bureucrat(const std::string new_name, int new_grade) : name(new_name) {
	
	if (new_grade < 1)
		throw Bureucrat::GradeTooHighException();
	else if (new_grade > 150)
		throw Bureucrat::GradeTooLowException();
	grade = new_grade;
	std::cout << "Copy Param constructor called" << std::endl;
}

/*std::string Bureucrat::GradeTooHighException() {
	return ("Grade Too High!");
}

std::string Bureucrat::GradeTooLowException() {
	return ("Grade Too Low!");
} */

const std::string Bureucrat::getName() {
	return this->name;
}

int Bureucrat::getGrade() {
	return this->grade;
}
