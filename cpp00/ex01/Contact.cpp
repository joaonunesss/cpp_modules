/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:56:36 by jmarinho          #+#    #+#             */
/*   Updated: 2024/01/23 16:38:41 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact()
{
    
}

Contact::Contact(std::string fname, std::string lname, std::string nick, std::string phonenbr, std::string secret)
{

    firstname = fname;
    lastname = lname;
    nickname = nick;
    phonenumber = phonenbr;
    darkestsecret = secret;

}
