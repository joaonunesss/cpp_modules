/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:51:13 by jmarinho          #+#    #+#             */
/*   Updated: 2024/08/09 17:04:07 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;

	a = b;
	b = tmp;
}

template <typename T>
T const &min(T const &a, T const &b)
{
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>
T const &max(T const &a, T const &b)
{
	if (a > b)
		return a;
	else
		return b;
}

#endif
