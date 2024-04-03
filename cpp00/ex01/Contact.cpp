/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:56:36 by jmarinho          #+#    #+#             */
/*   Updated: 2024/03/26 14:38:32 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact(){
    
}

Contact::Contact(std::string fname, std::string lname, std::string nick, std::string phonenbr, std::string secret)
{

    firstname = fname;
    lastname = lname;
    nickname = nick;
    phonenumber = phonenbr;
    darkestsecret = secret;

}

std::string Contact::get_firstname(){
    return firstname;
}

std::string Contact::get_lastname(){
    return lastname;
}

std::string Contact::get_nickname(){
     return nickname;
}

std::string Contact::get_phonenumber(){
     return phonenumber;
}

std::string Contact::get_darkestsecret(){
     return darkestsecret;
}