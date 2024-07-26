/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:07:07 by jmarinho          #+#    #+#             */
/*   Updated: 2024/07/26 16:27:48 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    public:

        PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm&operator=(const PresidentialPardonForm &other);

        PresidentialPardonForm(std::string name);
    
        void Class_Executer(std::string target) const;

        std::string target;
};

#endif
