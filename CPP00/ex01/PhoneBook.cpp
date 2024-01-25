/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:05:49 by jmarinho          #+#    #+#             */
/*   Updated: 2024/01/23 16:51:48 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>
#include <unistd.h>

PhoneBook::PhoneBook()
{
    id = 0;
}

void PhoneBook::add()
{ 
    std::string fname;
    std::string lname;
    std::string nick;
    std::string phonenbr;
    std::string secret;    
    
    std::cout << "\033c";
    std::cout << "First Name: " << std::endl;
    getline(std::cin, fname);
    std::cout << "Last Name: " << std::endl; 
    getline(std::cin, lname);
    std::cout << "Nickname: " << std::endl;
    getline(std::cin, nick);
    std::cout << "Phone number: " << std::endl;
    getline(std::cin, phonenbr);
    std::cout << "Darkest Secret: " << std::endl;
    getline(std::cin, secret);

    if(fname.empty() || lname.empty() || nick.empty() || phonenbr.empty() || secret.empty())
    {
        std::cout << "\033[1;31m" << "ERROR, no empty fields allowed" << "\033[0m" << std::endl 
            << "\033[1;33m" << "Press Enter to continue..." << "\033[0m" << std::endl;
        std::cin.ignore();
        add();
    }
    else
        contacts[id++ % 8] = Contact(fname, lname, nick, phonenbr, secret);
}

std::string PhoneBook::checklength(std::string str)
{    
    if (str.length() > 10)
        str = str.substr(0, 9) + ".";
    return (str);
    
}
void PhoneBook::search()
{
    PhoneBook phonebook;
    std::string index;
    int nbr;
    
    std::cout << "\033c";
    std::cout << "|  Index   |First Name| Last Name| Nickname |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    for (int i = 0; i < 8; i++)
    {
        std::cout << "|";
        std::cout << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << checklength(contacts[i].firstname) << "|";
        std::cout << std::setw(10) << checklength(contacts[i].lastname) << "|";
        std::cout << std::setw(10) << checklength(contacts[i].nickname) << "|";
        std::cout << std::endl;
    }
        std::cout << "Choose an index to display" << std::endl;
        std::cout << "Press BACK to return" << std::endl;
    while(1)  
    {
        getline(std::cin, index);
        
        nbr = atoi(index.c_str());
        if(index == "BACK")
            break;
        else if (nbr > 7 || nbr < 1)
            std::cout << "\033[1;33m" << "Index out of range. Try again" << "\033[0m" << std::endl;
        else if (nbr > id)
            std::cout  << "\033[1;33m" << "Nothing to display for this index" << "\033[0m" << std::endl; 
        else if (nbr <= id)
        { 
            std::cout << "\033c";
            std::cout  << "First Name: " << contacts[nbr - 1].firstname << std::endl;
            std::cout  << "Last Name: " << contacts[nbr - 1].lastname << std::endl;
            std::cout  << "Nickname: " << contacts[nbr -1].nickname << std::endl;
            std::cout  << "Phonenumber: " << contacts[nbr-1].phonenumber << std::endl;
            std::cout  << "Darkest Secret: " << contacts[nbr-1].darkestsecret << std::endl;

            std::cout << "Press enter to continue..." << std::endl;
            getline(std::cin, index);
            break;   
        }
    }
    
}

