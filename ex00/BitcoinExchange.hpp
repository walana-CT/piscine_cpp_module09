/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:40:49 by rficht            #+#    #+#             */
/*   Updated: 2024/02/20 09:28:29 by rficht           ###   ########.fr       */
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

class BitcoinExchange
{
private:
	/* data */
public:
	BitcoinExchange(/* args */);
	~BitcoinExchange();
};

BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::~BitcoinExchange()
{
}


void parth_vals();
bool isDateValid(const std::string& strInput);