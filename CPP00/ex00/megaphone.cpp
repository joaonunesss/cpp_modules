/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:34:45 by jmarinho          #+#    #+#             */
/*   Updated: 2023/12/05 12:32:43 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    size_t i;
    size_t k;

    i = 0;
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (EXIT_SUCCESS);
    }
    while (av[++i])
    {
        k = -1;
        while (av[i][++k])
             std::cout << (char)toupper(av[i][k]);
    }
    std::cout << std::endl;
}
