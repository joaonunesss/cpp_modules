/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:39:54 by jmarinho          #+#    #+#             */
/*   Updated: 2024/07/16 14:57:00 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {
  
  public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat&operator=(const Bureaucrat &other);
    Bureaucrat(const std::string name, int grade);

    const std::string getName();
    int getGrade();

    void    incrementGrade();
    void    decrementGrade();
    friend std::ostream& operator<<(std::ostream &os, const Bureaucrat &bur);

    class GradeTooHighException : public std::exception {
      public:
        const char* what() const throw();
        };

    class GradeTooLowException : public std::exception {
      public:
        const char* what() const throw();
        };

  private:
    const   std::string name;
    int     grade;
    
};

#endif