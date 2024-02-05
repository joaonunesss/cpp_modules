/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:20:03 by jmarinho          #+#    #+#             */
/*   Updated: 2024/01/23 16:17:16 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream> 
#include "Contact.hpp"

class PhoneBook {
    
    public:
    
    Contact contacts[8];
    int id;
    void add (void);
    void search (void);
    void exit (void);
    PhoneBook();

    std::string checklength(std::string str);
};

#endif