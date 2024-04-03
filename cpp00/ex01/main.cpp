/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:34:45 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/25 15:19:57 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"


int main(int ac, char **av)
{
    std::string option;
    PhoneBook phonebook;
    
    while(1)
    {
        
        std::cout << "\033c"; //clear the terminal 
        std::cout<< "Please insert a command" << std::endl;
        std::cout<< "ADD    " << std::endl;
        std::cout<< "SEARCH     " << std::endl;
        std::cout<< "EXIT" <<std::endl;

        std::cout<< "Type a command: " << std::endl;
        getline(std::cin, option);

        if (option == "ADD")
            phonebook.add();
        else if (option == "SEARCH")
            phonebook.search();
        else if (option == "EXIT")
        {
            std::cout << "\033c"; 
            break ;
        }
    }

}
