/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:44:15 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/04 15:05:43 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
    int_nbr = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other){
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed &other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        int_nbr = other.int_nbr;
    }
    return *this;
}

int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return int_nbr;
}

void Fixed::setRawBits( int const raw ){
    std::cout << "setRawBits member function called" << std::endl;
    int_nbr = raw;
}

Fixed::Fixed(const int other_int){
    std::cout << "Int constructor called" << std::endl;
    int_nbr = other_int * 1 << Fixed::bit_nbr; 
}

Fixed::Fixed(const float other_float){
    std::cout << "Float constructor called" << std::endl;
    int_nbr = roundf(other_float *(1 << Fixed::bit_nbr));
}

float Fixed::toFloat( void ) const{
    return (float)(int_nbr) / (1 << Fixed::bit_nbr);
}

int Fixed::toInt( void ) const{
    return int_nbr >> Fixed::bit_nbr;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

