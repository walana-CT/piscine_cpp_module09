/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btcUtils.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:19:58 by rficht            #+#    #+#             */
/*   Updated: 2024/02/28 11:36:04 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTCUTILS_HPP
# define BTCUTILS_HPP

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

bool	isNumber(const std::string& str);
bool	isDateValid(const std::string& strInput);
std::vector<std::vector<std::string> >	fileToVect(const std::string& inputFile, const char& separator);
double	ft_strtod(const std::string& str);
bool	isDateValid(const std::string& strInput);

#endif

