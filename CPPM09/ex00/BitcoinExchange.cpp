/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:52:45 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/10/13 14:04:55 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
# include <fstream>
#include <iostream>
#include <sstream>
#include <limits>
#include <stdexcept>

BitcoinExchange::BitcoinExchange()
{
};
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : _rates(other._rates)
{
};
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _rates = other._rates;
    return *this;
};

BitcoinExchange::~BitcoinExchange()
{
};

static bool isValidDate(const std::string &date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for(std::string::size_type i = 0; i < date.size(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;        
    }
    int year = (date[0] - '0') * 1000
                + (date[1] - '0') * 100
                + (date[2] - '0') * 10
                + (date[3] - '0');
    int month = (date[5] -'0') * 10 + (date[6] - '0');
    int day = (date[8] -'0') * 10 + (date[9] - '0');
    if (year < 1 || month < 1 || month > 12)
        return false;
     int daysInMonth[12] = {
          31, 28, 31, 30, 31, 30,
          31, 31, 30, 31, 30, 31
      };
    bool leapYear = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    if (leapYear)
        daysInMonth[1] = 29;
    return day >= 1 && day <=daysInMonth[month - 1];
}
static std::string trim(const std::string &text)
{
    std::string::size_type first = text.find_first_not_of(" \t\r\n");

    if (first == std::string::npos)
        return "";

    std::string::size_type last = text.find_last_not_of(" \t\r\n");

    return text.substr(first, last - first + 1);
}
static double parseValue(const std::string &text)
{
     std::istringstream ss(text);
     double value;
     if (!(ss >> value))
         throw std::runtime_error("bad input => " + text);
     ss >> std::ws;
     if (!ss.eof())
         throw std::runtime_error("bad input => " + text);
     // NaN no es igual a sí mismo.
     if (value != value)
         throw std::runtime_error("bad input => " + text);
     if (value < 0.0)
         throw std::runtime_error("not a positive number.");
     if (value > 1000.0)
         throw std::runtime_error("too large a number.");
     return value;
}
static double convertToDouble(const std::string &bc)
{
    // Crea un flujo que permite leer valores desde la cadena bc.
    std::istringstream ss(bc);
    double rate;
    //Envia datos de un flujo
    if (!(ss >> rate))
        throw std::runtime_error("Invalid database price: " + bc);
    //Extrae datos de un flujo ws == WhiteSpace
    ss >> std::ws;
    if (!ss.eof())
        throw std::runtime_error("Invalid database price: " + bc);
    
    if (!(rate >= 0.0) || rate > std::numeric_limits<double>::max())
        throw std::runtime_error("Invalid database price: " + bc);

      return rate;
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream rf(filename.c_str());

    if (!rf.is_open())
        throw std::runtime_error("Could not open file");
    std::string header;
    if (!std::getline(rf, header))
        throw std::runtime_error("Empty or unreadable database");
    if (!header.empty() && header[header.size() - 1] == '\r')
        header.erase(header.size() - 1);
    if (header != "date,exchange_rate")
        throw std::runtime_error("Invalid database header");
    std::string line;
    while(std::getline(rf, line))
    {
        if (!line.empty() && line[line.size() - 1] == '\r')
            line.erase(line.size() - 1);
        if (line.find(',') == std::string::npos)
            throw std::runtime_error("INVALID DATABASE LINE");
        std::string date = line.substr(0, line.find(','));
        std::string bc = line.substr(line.find(',') + 1);
        if (!isValidDate(date))
            throw std::runtime_error("Invalid database date" + date);
        double rate = convertToDouble(bc);
        _rates[date] = rate;
    }
    if (rf.bad())
        throw std::runtime_error("Could not read database");

    if (_rates.empty())
        throw std::runtime_error("Database contains no prices");

};
void BitcoinExchange::processInput(const std::string &filename) const
{
    std::ifstream rf(filename.c_str());
    if (!rf.is_open())
        throw std::runtime_error("Could not open file");
    std::string line;
    if (!std::getline(rf,line))
        throw std::runtime_error("Empty or unreadable input");
    if (!line.empty() && line[line.size() - 1] == '\r')
      line.erase(line.size() - 1);
    if (line != "date | value")
      throw std::runtime_error("Invalid input header: expected date | value; data.csv is loaded separately");
    while (std::getline(rf,line))
    {
        if (!line.empty() && line[line.size() - 1] == '\r')
          line.erase(line.size() - 1);
        try
        {
            std::string::size_type separator = line.find('|');
            if (separator == std::string::npos || line.find('|', separator + 1) != std::string::npos)
                throw std::runtime_error("bad input => " + line);
            std::string date = trim(line.substr(0, separator));
            std::string bc = trim(line.substr(separator + 1));
            if (!isValidDate(date))
                throw std::runtime_error("bad input => " + line);
            double value = parseValue(bc);
            //busca la primera fecha posterior a la solicitada
            std::map<std::string, double>::const_iterator it = _rates.upper_bound(date); 
            if (it == _rates.begin())
                throw std::runtime_error("No exchange rate available for " + date);
            --it;
             double rate = it->second;

            std::cout   << date
                        << " => " << value
                        << " = " << value * rate
                        << '\n';
        }
        catch(const std::exception& e)
        {
           std::cout << "Error: " << e.what() << '\n';
        }
          
    }
    if (rf.bad())
    throw std::runtime_error("Could not read input");
};
