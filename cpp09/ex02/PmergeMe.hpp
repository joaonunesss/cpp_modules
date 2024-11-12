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

		static bool	FordJohnsonSelector(char **av, int ac);

	private:
		bool		vectorFordJohnson(char **av, int ac);
		void		recursiveDivide(std::vector<std::pair<int, int> > &pairs);
		void		mergeVectors(std::vector<std::pair<int , int> > &left, std::vector<std::pair<int , int> > &right, std::vector<std::pair<int , int> > &result);
		void		insertionSort(std::vector<int> &vector, std::vector<std::pair<int, int> > &pairs);

		bool		ListFordJohnson(char **av, int ac);
		void		divideLists(std::list<int> &list);
			
	/* private:
		void				VectorFordJohnson(std::vector<int> vector);
		std::vector<int>	divideVectors(std::vector<int> vector);

		void				ListFordJohnson(std::list<int> list);
		std::list<int>		divideLists(std::list<int> list);
		
		std::vector<int>	jacobSequence(int size); */
};


#endif