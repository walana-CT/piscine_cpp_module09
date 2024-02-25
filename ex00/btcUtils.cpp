/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btcUtils.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:19:55 by rficht            #+#    #+#             */
/*   Updated: 2024/02/25 10:26:57 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"btcUtils.hpp"

bool isNumber(const std::string& str)
{
	for (size_t i = 0; i < str.size(); i++)
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-')
			return false;
	return true;
}

std::vector<std::vector<std::string> > fileToVect(const std::string& inputFile, const char& separator)
{
	std::vector<std::vector<std::string> > content;
	std::vector<std::string> row;
	std::string line, word;
	std::fstream file (inputFile.c_str(), std::ios::in);

	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
			std::stringstream str(line);
			while(getline(str, word, separator))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
	{
		std::cout << inputFile << ": " << std::endl;
		throw(InvalidFileException());
	}
	file.close();	

	return content;
}

double	ft_strtod(const std::string& str)
{
	double result;

	if (str.empty())
		return 0;
	char	*cstr = new char[str.length() + 1];
	strcpy(cstr, str.c_str());
	result = strtod (cstr, 0);
	delete [] cstr;
	return(result);
}

bool isDateValid(const std::string& strInput)
{

	std::tm date = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	if (strInput.size() != 10 || strInput[4] != '-' || strInput[7] != '-')
		return(false);
	
	if (!strptime(strInput.c_str(), "%Y-%m-%d", &date))
		return(false);

	//february checks 
	if (date.tm_year % 4 != 0 || (date.tm_year % 100 == 0 && date.tm_year % 400 != 0))
		if (date.tm_mon == 1 && date.tm_mday == 29)
			return false;
	if (date.tm_mon == 1 && (date.tm_mday == 30 || date.tm_mday == 31))
		return false;

	//30 days month checks
	if (date.tm_mon == 3 || date.tm_mon == 5 || date.tm_mon == 8 ||  date.tm_mon == 10)
		if (date.tm_mday == 31)
			return false;

	return true;
}
