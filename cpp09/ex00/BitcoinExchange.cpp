/* ************************************************************************** */
/*                                                                            */
/*                                                        :::     :::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:19:38 by jmarinho          #+#    #+#             */
/*   Updated: 2024/09/09 11:37:56 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : result(0) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;	
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other)
	{
		textData = other.textData;
		csvData = other.csvData;	
		result = other.result;
		date = other.date;
		btc = other.btc;
	}
	return *this;
}

int	BitcoinExchange::loadCsv(std::string data_file)
{
	std::ifstream file(data_file.c_str());
	std::string line;
	std::string key, nbr;

	if (!file.is_open())
	{
		std::cerr << "Error opening data_file" << std::endl;
		return (EXIT_FAILURE);
	}
	while(std::getline(file, line))
	{
		std::stringstream splcsv_it(line);
		
		if (std::getline(splcsv_it, key, ',') && std::getline(splcsv_it, nbr, '\n'))
		{
			key = key.c_str();
			nbr = nbr.c_str();
			csvData[key] = nbr;
		}
	}
	file.close();
	return (EXIT_SUCCESS);
}

std::string strTrim(const std::string& str)
{
    size_t start = 0;
    size_t end = str.length() - 1;

    while (start < str.length() && std::isspace(str[start]))
        ++start;
    while (end > start && std::isspace(str[end]))
        --end;

    return str.substr(start, end - start + 1);
}

int checkDate(std::string date)
{
	if (date.empty() | (date.length() != 10))
		return EXIT_FAILURE;
	
	for (size_t i = 0; i < date.length(); i++)
	{
		if ((i == 4 || i == 7) && date[i] != '-')
		{
			std::cerr << "Error: date must be in YYYY-MM-DD format." << std::endl;
			return EXIT_FAILURE;
		}
		else if ((i != 4 && i != 7) && !std::isdigit(date[i]))
		{
            std::cerr << "Error: date must be in YYYY-MM-DD format." << std::endl;
            return EXIT_FAILURE;
		}
	}
 
    int year = atof(date.substr(0, 4).c_str());
    int month = atof(date.substr(5, 2).c_str());
    int day = atof(date.substr(8, 2).c_str());

	if (year < 1900 || year > 2100)
	{
		std::cerr << "Error: " << year << " year out of range (1900 - 2100)." << std::endl;
		return EXIT_FAILURE;
	}

	if (month < 1 || month > 12)
	{
		std::cerr << "Error: " << month << " month out of range (01 - 12)." << std::endl;
		return EXIT_FAILURE;
	}

	if (day < 1 || day > 31)
	{
		std::cerr << "Error: " << day << " day out of range (01 - 31)." << std::endl;
		return EXIT_FAILURE;
	}

	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
		{
			std::cerr << "Error: day " << day << " out of range for month " << month << "." << std::endl;
			return EXIT_FAILURE;
		}
	}
    else if (month == 2)
	{
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if ((isLeap && day > 29) || (!isLeap && day > 28))
		{
			std::cerr << "Error: day " << day << " out of range for month " << month << ". Year isLeap " << isLeap << std::endl;
			return EXIT_FAILURE;
		}
	}

    return EXIT_SUCCESS;
}

int checkBtc(std::string btc)
{
	if (btc.empty())
		return EXIT_FAILURE;

	std::stringstream ss(btc);
    double nbr;
    ss >> nbr;

    if (ss.fail() || !ss.eof())
	{
        std::cerr << "Error: invalid number format." << std::endl;
        return EXIT_FAILURE;
    }

	if (nbr < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return EXIT_FAILURE;
	}
	else if (nbr > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}

int BitcoinExchange::exchange(std::string txt_file)
{
	std::ifstream	file(txt_file.c_str());
	std::string 	line;
 	size_t 			pos;

	if (!file.is_open())
	{
		std::cerr << "Error opening data_file" << std::endl;
		return (EXIT_FAILURE);
	}
	while(std::getline(file, line))
	{
		if (line.empty() || line == "date | value" || line == "date|value")
			continue;

		pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = line.substr(0, pos);
		btc = line.substr(pos + 1, line.length());
		
		date = strTrim(date);
		btc = strTrim(btc);

		if (checkDate(date) | checkBtc(btc))
			continue;

		std::map<std::string, std::string>::iterator csv_it = csvData.lower_bound(date);		
		if (csv_it->first == date && csv_it != csvData.end())
		{
			result = atof(btc.c_str()) * atof(csv_it->second.c_str());
			std::cout << date << " => " << btc.c_str() << " = " << result << std::endl;
		}
		else
		{
			if (csv_it != csvData.begin())
			{
				csv_it--;
				result = atof(btc.c_str()) * atof(csv_it->second.c_str());
				std::cout << date << " => " << btc.c_str() << " = " << result << std::endl;
			}
			else
			{
				result = atof(btc.c_str()) * atof(csv_it->second.c_str());
				std::cout << date << " => " << btc.c_str() << " = " << result << std::endl;
			}
		}
	}

	file.close();
	return (EXIT_SUCCESS);
}
