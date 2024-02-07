/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:58:08 by jmarinho          #+#    #+#             */
/*   Updated: 2024/02/06 15:09:24 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
    this->value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value){
    this->value = value * 1 << Fixed::bits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value){
    this->value = roundf(value * (1 << Fixed::bits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other){
        std::cout << "Copy assignment operator called" << std::endl;
        this->value = other.value;
    }
    return *this;
}

float Fixed::toFloat() const {
    return static_cast<float>(this->value) / (1 << Fixed::bits);
}

int Fixed::toInt() const {
    return this->value >> Fixed::bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed &other) const {
    return this->value > other.value;
}

bool Fixed::operator<(const Fixed &other) const{
    return this->value < other.value;
}
bool Fixed::operator>=(const Fixed &other) const{
    return this->value >= other.value;
}
bool Fixed::operator<=(const Fixed &other) const{
    return this->value <= other.value;
}
bool Fixed::operator==(const Fixed &other) const{
    return this->value == other.value;
}
bool Fixed::operator!=(const Fixed &other) const{
    return this->value != other.value;
}

Fixed Fixed::operator+(const Fixed &other) const {
    
    Fixed result;
    
    result.value = this->value + other.value;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    
    Fixed result;
    
    result.value = this->value - other.value;
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    
    Fixed result;
    
    result.value = (this->value * other.value) >> Fixed::bits; // Adjust for fixed-point representation
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    
    Fixed result;
    
    result.value = (this->value << Fixed::bits) / other.value; // Adjust for fixed-point representation
    return result;
}

Fixed &Fixed::operator++() {    // pre-increment
    
    this->value++;
    
    return *this;
}

Fixed Fixed::operator++(int) {  // post-increment
    
    Fixed temp(*this);
    
    this->value++;
    
    return temp;
}

Fixed &Fixed::operator--() {    // pre-decrement
    
    this->value--;
    
    return *this;
}

Fixed Fixed::operator--(int) {  // post-decrement
    
    Fixed temp(*this);
    
    this->value--;
    
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
    
    if (a.value < b.value)
        return a;
    else
        return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    
    if (a.value < b.value)
        return a;
    else
        return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){

    if (a.value > b.value)
        return a;
    else
        return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    
    if (a.value > b.value)
        return a;
    else
        return b;
}
