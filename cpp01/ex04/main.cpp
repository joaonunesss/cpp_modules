/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:30:46 by jmarinho          #+#    #+#             */
/*   Updated: 2024/02/05 10:36:34 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main()
{
    std::string s1 = "Quim";
    std::string s2 = "Manel";
    std::ifstream inputFile("original.txt");

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }

    std::string text((std::istreambuf_iterator<char>(inputFile)), (std::istreambuf_iterator<char>()));

    size_t pos = text.find(s1);

    while (pos != std::string::npos)
    {
        text.erase(pos, s1.length());
        text.insert(pos, s2);
        pos = text.find(s1, pos + s2.length());
    }
    
    inputFile.close();

    std::ofstream outputFile("modified_text.txt");
    outputFile << text;
    
}