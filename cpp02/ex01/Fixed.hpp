/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:58:46 by jmarinho          #+#    #+#             */
/*   Updated: 2024/02/06 14:10:05 by jmarinho         ###   ########.fr       */
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
    
    private:

        int value;
        static int const bits = 8;
    
};

#endif