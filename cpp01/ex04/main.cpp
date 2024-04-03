/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:30:46 by jmarinho          #+#    #+#             */
/*   Updated: 2024/04/03 11:30:47 by jmarinho         ###   ########.fr       */
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
        std::cout << "Error opening the file!" << std::endl;
        return 1;
    }

    //esta linha permite ler todo conteudo de original.txt para a string text e assim usar os metodos de std::string
    std::string text((std::istreambuf_iterator<char>(inputFile)), (std::istreambuf_iterator<char>()));

    size_t pos = 0;

    while (pos != std::string::npos)
    {
        text.erase(pos, s1.length());
        text.insert(pos, s2);
        pos = text.find(s1, pos + s2.length());
    }
    
    inputFile.close();

    std::ofstream outputFile("original.replace.txt");
    outputFile << text;
    
}