/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:41:04 by rficht            #+#    #+#             */
/*   Updated: 2024/02/25 10:11:11 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool is_number(const std::string& str)
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


/*void display_data(std::map<std::string , float> dataBase)
{
	for (std::map<std::string, float>::iterator iter = dataBase.begin(); iter != dataBase.end(); ++iter) {
		std::cout << "Key: " << iter->first << ", Value: " << iter->second << std::endl;
	}
}*/

/*void display_array(const std::vector<std::vector<std::string> >& content)
{
	for(long unsigned int i=1; i < content.size(); i++)
	{
		for (size_t j = 0; j < content[i].size(); j++)
			std::cout << content[i][j];
		std::cout << std::endl;
	}
}*/

void bitcoinExchange(const std::string& inputFile)
{
	std::map<std::string , float> dataBase = importData();
	evaluateInput(dataBase, inputFile);
	
	return ;
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


std::map<std::string, float> importData()
{
	std::map<std::string , float> dataBase;
	std::vector<std::vector<std::string> > content = fileToVect("data.csv", ',');
	if (content[0].size() != 2 || content[0][0] != "date" || content[0][1] != "exchange_rate")
	{
		std::cout << "data.csv" << ": data base expect following format: date,exchange_rate" << std::endl;
		throw(InvalidFormatException());		
	}

	for(long unsigned int i=1; i < content.size(); i++)
	{
		if (!isDateValid(content[i][0]))
		{
			std::cout << "data.csv" << ": " << content[i][0] << " line " << i << std::endl;		
			throw(InvalidFormatException());
		}
		dataBase[content[i][0]] = ft_strtod(content[i][1]);
	}
	return (dataBase);
}

std::string trimSpaces(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");
    if (start == std::string::npos || end == std::string::npos)
	{
		return ("");
    }
   	return(str.substr(start, end - start + 1));
}

bool isContentValid(std::vector<std::vector<std::string> >& content)
{
		
	if (content.size() == 0 || content[0].size() != 2)
		return false;

	for(size_t i = 0; i < content.size(); i++)
		for (size_t j = 0; j < content[i].size(); j++)
			content[i][j] = trimSpaces(content[i][j]);

	if ( content[0][0] != "date" || content[0][1] != "value")
		return false;
	
	return true;
}

void evaluateInput(std::map<std::string , float> dataBase ,const std::string& inputFile)
{
	double	value;
	std::vector<std::vector<std::string> > content = fileToVect(inputFile, '|');

	if (!isContentValid(content))
	{
		std::cout << inputFile << ": input data base expect following format: date|value" << std::endl;
		throw(InvalidFormatException());		
	}

	for(long unsigned int i=1; i < content.size(); i++)
	{
		if (content[i].size() != 2 || content[i][1].empty())
			{std::cout << "Error: " << "line " << i << " should contain 2 elements." << std::endl; continue;}
		if (!isDateValid(content[i][0]))
			{std::cout << "Error: " << "line " << i << " invalide date format. (" << content[i][0] << ")" << std::endl; continue;}
		if (!is_number(content[i][1]))
			{std::cout << "Error: " << "line " << i << " value is not a number. (" << content[i][1] << ")" << std::endl; continue;}
		value = ft_strtod(content[i][1]);
		if (value < 0 || value > 1000)
			{std::cout << "Error: " << "line " << i << " values should be between 0 and 1000. (" << content[i][1] << ")" << std::endl; continue;}
		
		std::map<std::string , float>::iterator itTarget = dataBase.end();
		for (std::map<std::string , float>::iterator it = dataBase.begin(); it != dataBase.end(); it++)
		{
			if (content[i][0] == it->first)
				itTarget = it;
			else if (content[i][0] > it->first && it->first > itTarget->first)
				itTarget = it;
		}
		
		std::cout << "searched  date: " << content[i][0] << " found key: " << itTarget->first << std::endl;
		
		if (itTarget == dataBase.end() && itTarget->first != content[i][0])
			std::cout << "Error: " << "line " << i << " no value have been found for this key. (" << content[i][0] << ")" << std::endl;
		else
			std::cout << content[i][0] << " => " << content[i][1] << " = " << value * itTarget->second << std::endl;			
	}
	return ;
}