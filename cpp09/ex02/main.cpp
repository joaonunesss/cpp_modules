/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:46:08 by jmarinho          #+#    #+#             */
/*   Updated: 2024/09/13 14:34:27 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* Ford-Johnson or Merge Insertion

For example, consider the problem of sorting 21 elements. We start by comparing
the ten pairs K 1 : K 2, K3: K4, ... , K19: K2o; then we sort the ten larger elements
of the pairs, using merge insertion. 

Diff between Vector and List

Vectors:
	Offer fast random access, better cache performance, and efficient end insertions,
	making them ideal for read-heavy sequences.
Lists:
	Provide better performance for insertions and deletions at arbitrary positions and
	are suited for scenarios where such operations dominate. More efficient for
	applications that involve frequent insertions and deletions at arbitrary
	positions (O(1) for adding/removing at the head or tail).

*/

//https://github.com/nerraou/Ford-Johnson-algorithm?tab=readme-ov-file

int main (int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Invalid number of args!" << std::endl;
		return EXIT_FAILURE;
	}

	if (PmergeMe::FordJohnsonSelector(av, ac))
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}