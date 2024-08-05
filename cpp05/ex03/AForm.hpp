/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:07:05 by jmarinho          #+#    #+#             */
/*   Updated: 2024/08/05 17:43:36 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[36m"
# define RESET "\033[37m"

class AForm {

    public:

		AForm();
		virtual ~AForm() = 0;
		AForm(const AForm &other);
        AForm(const std::string new_name, bool new_is_signed, const int new_grade_to_sign, const int new_grade_to_execute);
		AForm&operator=(const AForm &other);
        

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

        void                execute(Bureaucrat const & executor) const;

        virtual void Class_Executer(std::string target) const = 0;
		
    private:
	
        const std::string	name;
        bool            	is_signed;
        const int           grade_to_sign;
        const int           grade_to_execute;      
};

std::ostream& operator<<(std::ostream &os, const AForm &bur);

#endif