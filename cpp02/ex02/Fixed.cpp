/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:58:08 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/08 12:30:16 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
    int_nbr = 0;
}

Fixed::~Fixed() {
    //std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    //std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other){
        //std::cout << "Copy assignment operator called" << std::endl;
        int_nbr = other.int_nbr;
    }
    return *this;
}

int Fixed::getRawBits( void ) const{
    //std::cout << "getRawBits member function called" << std::endl;
    return int_nbr;
}

void Fixed::setRawBits( int const raw ){
    //std::cout << "setRawBits member function called" << std::endl;
    int_nbr = raw;
}

Fixed::Fixed(const int other_int){
    //std::cout << "Int constructor called" << std::endl;
    int_nbr = other_int * 1 << Fixed::bit_nbr;
}

Fixed::Fixed(const float other_float){
    //std::c out << "Float constructor called" << std::endl;
    int_nbr = roundf(other_float * (1 << Fixed::bit_nbr));
}

float Fixed::toFloat() const {
    return (float)(int_nbr) / (1 << Fixed::bit_nbr);
}

int Fixed::toInt() const {
    return int_nbr >> Fixed::bit_nbr;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed &other){
    return int_nbr > other.int_nbr;
}

bool Fixed::operator<(const Fixed &other){
    return int_nbr < other.int_nbr;
}

bool Fixed::operator>=(const Fixed &other){
    return int_nbr >= other.int_nbr;
}

bool Fixed::operator<=(const Fixed &other){
    return int_nbr <= other.int_nbr;
}

bool Fixed::operator==(const Fixed &other){
    return int_nbr == other.int_nbr;
}

bool Fixed::operator!=(const Fixed &other){
    return int_nbr != other.int_nbr;
}

Fixed Fixed::operator+(const Fixed &other){
    
    Fixed result;
    
    result.int_nbr = int_nbr + other.int_nbr;
    return result;
}

Fixed Fixed::operator-(const Fixed &other){
    
    Fixed result;
    
    result.int_nbr = int_nbr - other.int_nbr;
    return result;
}

Fixed Fixed::operator*(const Fixed &other){
    
    Fixed result;
    
    result.int_nbr = (int_nbr * other.int_nbr) >> Fixed::bit_nbr; // Adjust for fixed-point representation
    return result;
}

Fixed Fixed::operator/(const Fixed &other){
    
    Fixed result;
    
    result.int_nbr = (int_nbr << Fixed::bit_nbr) / other.int_nbr; // Adjust for fixed-point representation
    return result;
}

Fixed Fixed::operator++(){    //pre-increment
    
    ++int_nbr;
    
    return *this;
}

Fixed Fixed::operator--(){    //pre-decrement
    
    --int_nbr;
    
    return *this;
}

Fixed Fixed::operator++(int){  //post-increment
    
    Fixed temp(*this);
    
    ++int_nbr;
    // returned value should be a copy of the object before increment
    return temp;
}


Fixed Fixed::operator--(int) {  //post-decrement
    
    Fixed temp(*this);
    
    --int_nbr;
    // returned value should be a copy of the object before increment
    return temp;
}

const Fixed& Fixed::min(Fixed &a, Fixed &b){
    
    if (a.int_nbr < b.int_nbr)
        return a;
    else
        return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    
    if (a.int_nbr < b.int_nbr)
        return a;
    else
        return b;
}

const Fixed& Fixed::max(Fixed &a, Fixed &b){

    if (a.int_nbr > b.int_nbr)
        return a;
    else
        return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    
    if (a.int_nbr > b.int_nbr)
        return a;
    else
        return b;
}
