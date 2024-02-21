/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:40:49 by rficht            #+#    #+#             */
/*   Updated: 2024/02/21 10:34:58 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <ctime>
#include <string.h>
#include <stdlib.h>


class InvalidFileException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{	return ("couldn't open file");	}
};


class InvalidFormatException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{	return ("data base does not follow the rules");	}
};







std::map<std::string, float> importData();
void evaluateInput(std::map<std::string , float> dataBase ,const std::string& inputFile);
void bitcoinExchange(const std::string& inputFile);
bool isDateValid(const std::string& strInput);
