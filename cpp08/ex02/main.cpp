/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:12:42 by jmarinho          #+#    #+#             */
/*   Updated: 2024/08/13 16:11:53 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "top " << mstack.top() << std::endl;
	
	mstack.pop();
	std::cout << "size " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

						std::cout << RED << "NOW WITH STD::LIST TO COMPARE" << RESET << std::endl;

    // Create a std::list<int> to mimic MutantStack
    std::list<int> myList;

    // Push elements onto the list (like push into a stack)
    myList.push_back(5);
    myList.push_back(17);

    // Display the top element (last pushed element in the list)
    std::cout << "top " << myList.back() << std::endl;

    // Pop an element from the list (remove the last element)
    myList.pop_back();
    std::cout << "size " << myList.size() << std::endl;

    // Push more elements
    myList.push_back(3);
    myList.push_back(5);
    myList.push_back(737);
    myList.push_back(0);

    // Iterator definitions
    std::list<int>::iterator it2 = myList.begin();
    std::list<int>::iterator ite2 = myList.end();

    // Increment and decrement the iterator
    ++it2;
    --it2;

    // Print all elements using iterators
    while (it2 != ite2) {
        std::cout << *it2 << std::endl;
        ++it2;
    }
	
    return 0;
}
