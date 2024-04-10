/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:43:37 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/08 12:28:57 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

  public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &other);
    Fixed& operator=(const Fixed &other);
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );

    Fixed(const int other_int); //converts int to fixed
    Fixed(const float other_float); //converts float to fixed

    float toFloat( void ) const;
    int toInt( void ) const;

    bool operator>(const Fixed &other);
    bool operator<(const Fixed &other);
    bool operator>=(const Fixed &other);
    bool operator<=(const Fixed &other);
    bool operator==(const Fixed &other);
    bool operator!=(const Fixed &other);

    Fixed operator+(const Fixed &other);
    Fixed operator-(const Fixed &other);
    Fixed operator*(const Fixed &other);
    Fixed operator/(const Fixed &other);

    Fixed operator++();
    Fixed operator--();
    Fixed operator++(int);
    Fixed operator--(int);

    static const Fixed& min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static const Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);

  private:
    int int_nbr;
    static const int bit_nbr = 8;
    
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif