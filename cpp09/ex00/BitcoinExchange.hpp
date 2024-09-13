/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:19:41 by jmarinho          #+#    #+#             */
/*   Updated: 2024/09/09 16:18:48 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_hpp
#define	BitcoinExchange_hpp 


#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>

class BitcoinExchange {
	
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		int		loadCsv(std::string data_file);
		int		exchange(std::string txt_file);

		std::map<std::string, std::string> 	textData;
		std::map<std::string, std::string>	csvData;

		double		result;
		std::string date;
		std::string btc;
		
};

#endif