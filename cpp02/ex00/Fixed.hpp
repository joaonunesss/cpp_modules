/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:43:37 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/03 14:17:01 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

  public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &other);
    Fixed&operator=(const Fixed &other);
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );

  private:
    int int_nbr;
    static const int bit_nbr = 8;
    
};

#endif