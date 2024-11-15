/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:43:03 by jmarinho          #+#    #+#             */
/*   Updated: 2024/09/10 16:27:46 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <cstdlib>
#include <cctype>

#include <stack> //stack is LIFO (Last In First Out)

class RPN {
	public:

		RPN();
        ~RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
	
		static bool				isValid(std::string str);
		
	private:
		int				calculate_rpn(std::string str);
		
		double				result;
		std::stack<double>	stack;
};

#endif