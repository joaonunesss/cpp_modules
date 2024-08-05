/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:07:05 by jmarinho          #+#    #+#             */
/*   Updated: 2024/08/05 16:11:10 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp" 

class Bureaucrat;

class Form {

    public:

		Form();
		~Form();
		Form(const Form &other);
        Form(const std::string new_name, bool new_is_signed, const int new_grade_to_sign, const int new_grade_to_execute);
		Form&operator=(const Form &other);
        

        class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
        };

        std::string	        getName() const;
        bool				getIs_Signed() const;
        int			        getGrade_To_Sign() const;
		int			        getGrade_To_Execute() const;
	
		void				beSigned(Bureaucrat	*bureaucrat);
		
    private:
	
        const std::string	name;
        bool            	is_signed;
        const int           grade_to_sign;
        const int           grade_to_execute;      
};

std::ostream& operator<<(std::ostream &os, const Form &bur);

#endif