/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:20:03 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/26 14:39:12 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream> 
#include "Contact.hpp"

class PhoneBook {
    
    public:
        PhoneBook();
        Contact contacts[8];
        void add (void);
        void search (void);
        void exit (void);
        void errormsg();
        
        int id = 0;

        std::string checklength(std::string str);
};

#endif