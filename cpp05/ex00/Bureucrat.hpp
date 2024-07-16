/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureucrat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:39:54 by jmarinho          #+#    #+#             */
/*   Updated: 2024/07/16 14:18:08 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREUCRAT_HPP
#define BUREUCRAT_HPP

#include <iostream>

class Bureucrat {
  
  public:
    Bureucrat();
    ~Bureucrat();
    Bureucrat(const Bureucrat &other);
    Bureucrat&operator=(const Bureucrat &other);
    Bureucrat(const std::string name, int grade);

    const std::string getName();
    int getGrade();

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() {
            return "Grade Too High!";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() {
            return "Grade Too Low!";
        }
    };

  private:
    const std::string name;
    int grade;
    
};

#endif