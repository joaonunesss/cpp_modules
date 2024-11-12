/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:56:24 by jmarinho          #+#    #+#             */
/*   Updated: 2024/09/13 14:47:03 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cmath>

class PmergeMe {
	
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
	
	private:
		static void			VectorFordJohnson(std::vector<int> vector);
		static std::vector<int>	divideVectors(std::vector<int> vector);

		static void			ListFordJohnson(std::list<int> list);
		static std::list<int>		divideLists(std::list<int> list);
		
		static std::vector<int>	jacobSequence(int size);
};


#endif