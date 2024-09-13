/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:19:14 by jmarinho          #+#    #+#             */
/*   Updated: 2024/08/12 17:32:55 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

class EasyFindException : public std::exception {
	public:
		const char *what() const throw() {
			return "easyfind: exception: element not found within container";
   		}
};

template <typename T>
typename T::iterator easyfind(T &container, int nbr) {
	
	typename T::iterator it = std::find(container.begin(), container.end(), nbr);
    if (it == container.end()) {
        throw EasyFindException();
    }
    return it;
}

#endif