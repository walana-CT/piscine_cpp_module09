/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:40:49 by rficht            #+#    #+#             */
/*   Updated: 2024/02/20 09:59:28 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Date.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <ctime>
#include <string.h>
#include <stdlib.h>


class GradeTooHighException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{	return ("You should lower your expectations");	}
};










std::map<std::string, float> csvToMap();
void bitcoinExchange(const std::string& inputFile);
bool isDateValid(const std::string& strInput);
