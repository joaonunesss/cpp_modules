/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:58:08 by jmarinho          #+#    #+#             */
/*   Updated: 2024/02/06 13:59:30 by jmarinho         ###   ########.fr       */
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
