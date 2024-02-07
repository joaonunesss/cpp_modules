/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:58:46 by jmarinho          #+#    #+#             */
/*   Updated: 2024/02/06 15:07:16 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    
    public:
    
        Fixed();
        Fixed(const int value); //converts int to fixed
        Fixed(const float value); //converts float to fixed
        Fixed(const Fixed &other);
        ~Fixed();

        Fixed &operator=(const Fixed &other);
        
        float toFloat(void) const;
        int toInt(void) const;
        void setRawBits(int const raw);    
        int getRawBits(void);

        friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
    
        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;
    
        Fixed &operator++();    // pre-increment
        Fixed operator++(int);  // post-increment
        Fixed &operator--();    // pre-decrement
        Fixed operator--(int);  // post-decrement

        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
        
    private:

        int value;
        static int const bits = 8;
    
};

#endif