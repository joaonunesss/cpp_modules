/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:12:42 by jmarinho          #+#    #+#             */
/*   Updated: 2024/09/30 14:36:05 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "OtherClasses.hpp"

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[36m"
# define RESET "\033[37m"

Base	*generate(void)
{
	std::srand(time(0));
	int random = rand() % 3;

	if (random == 0)
	{
		std::cout << "A created" << std::endl;
		return new A();
	}
	else if (random == 1)
	{
		std::cout << "B created" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "C created" << std::endl;
		return new C();
	}
}

void	identify(Base *p)
{
	std::cout << "Identify with Base ptr";
	
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (const std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cout << "Invalid type" << std::endl;
			}
		}
	}
}

int		main()
{
    Base *c;
    
    c = generate();

    std::cout << std::endl;
    identify(c);
    identify(c);

    delete c;
}
