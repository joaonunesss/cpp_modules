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
#include <deque>
#include <ctime>
#include <iomanip>
#include <cmath>

class PmergeMe {
	
	public:

		static bool	FordJohnsonSelector(char **av, int ac);

	private:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		
		bool		vectorFordJohnson(char **av, int ac);
		void		createPairsForVectors(std::vector<int> &vector, std::vector<std::pair<int, int> > &pairs);
		void		recursiveDivideVectors(std::vector<std::pair<int, int> > &pairs);
		void		mergeVectors(std::vector<std::pair<int , int> > &left, std::vector<std::pair<int , int> > &right, std::vector<std::pair<int , int> > &result);
		void		insertionSort(std::vector<int> &vector, std::vector<std::pair<int, int> > &pairs);
		void		binarySearchForVectors(std::vector<int> &vector, int number);

		bool		dequeFordJohnson(char **av, int ac);
		void		createPairsForDeques(std::deque<int> &deque, std::deque<std::pair<int, int> > &pairs);
		void		recursiveDivideForDeque(std::deque<std::pair<int, int> > &pairs);
		void		mergeDeques(std::deque<std::pair<int , int> > &left, std::deque<std::pair<int , int> > &right, std::deque<std::pair<int , int> > &result);
		void		insertionSortForDeques(std::deque<int> &deque, std::deque<std::pair<int, int> > &pairs);
		void		binarySearchForDeques(std::deque<int> &deque, int number);


};


#endif