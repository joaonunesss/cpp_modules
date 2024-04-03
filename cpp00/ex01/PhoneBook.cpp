/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:05:49 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/26 14:37:05 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>
#include <unistd.h>

PhoneBook::PhoneBook(){

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
    if(fname.empty())
    {
        errormsg();
        return ;
    }
    std::cout << "Last Name: " << std::endl; 
    getline(std::cin, lname);
    if(lname.empty())
    {
        errormsg();
        return ;
    }
    std::cout << "Nickname: " << std::endl;
    getline(std::cin, nick);
    if(nick.empty())
    {
        errormsg();
        return ;
    }
    std::cout << "Phone number: " << std::endl;
    getline(std::cin, phonenbr);
    if(phonenbr.empty())
    {
        errormsg();
        return ;
    }
    std::cout << "Darkest Secret: " << std::endl;
    getline(std::cin, secret);
    if(secret.empty())
    {
        errormsg();
        return ;
    }
    contacts[id++ % 8] = Contact(fname, lname, nick, phonenbr, secret);
}

void PhoneBook::errormsg(){
    
    std::cout << "\033[1;31m" << "ERROR, no empty fields allowed" << "\033[0m" << std::endl 
            << "\033[1;33m" << "Press Enter to continue..." << "\033[0m" << std::endl;
    std::cin.get();
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
    
    std::cout << "\033c"; //clear the terminal
    std::cout << "|  Index   |First Name| Last Name| Nickname |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    for (int i = 0; i < 8; i++)
    {
        std::cout << "|";
        std::cout << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << checklength(contacts[i].get_firstname()) << "|";
        std::cout << std::setw(10) << checklength(contacts[i].get_lastname()) << "|";
        std::cout << std::setw(10) << checklength(contacts[i].get_nickname()) << "|";
        std::cout << std::endl;
    }
    std::cout << "Choose an index to display" << std::endl;
    std::cout << "Comand BACK to return" << std::endl;
    while(1)  
    {
        getline(std::cin, index);
        
        nbr = atoi(index.c_str());
        if(index == "BACK")
            break;
        else if (nbr > 8 || nbr < 1)
            std::cout << "\033[1;33m" << "Index out of range. Try again" << "\033[0m" << std::endl;
        else if (nbr > id)
            std::cout  << "\033[1;33m" << "Nothing to display for this index" << "\033[0m" << std::endl; 
        else if (nbr <= id)
        { 
            std::cout << "\033c"; //clear the terminal
            std::cout  << "First Name: " << contacts[nbr - 1].get_firstname() << std::endl;
            std::cout  << "Last Name: " << contacts[nbr - 1].get_lastname() << std::endl;
            std::cout  << "Nickname: " << contacts[nbr -1].get_nickname() << std::endl;
            std::cout  << "Phonenumber: " << contacts[nbr-1].get_phonenumber() << std::endl;
            std::cout  << "Darkest Secret: " << contacts[nbr-1].get_darkestsecret() << std::endl;

            std::cout << "Press enter to continue..." << std::endl;
            getline(std::cin, index);
            break;   
        }
    }
    
}

