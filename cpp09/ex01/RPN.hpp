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
#include <stack>
#include <cstdlib>
#include <cctype>

class RPN {
	public:

		RPN();
        ~RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);

		double				calculate_rpn(std::string str);
		bool				isValid(std::string str);
		
		double				result;
		std::stack<double>	stack;
};

#endif