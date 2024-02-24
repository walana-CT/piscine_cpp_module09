/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:41:04 by rficht            #+#    #+#             */
/*   Updated: 2024/02/24 10:10:24 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool is_number(const std::string& str)
{
	char*	pEnd;

	char	*cstr = new char[str.length() + 1];
	strcpy(cstr, str.c_str());
	strtod (cstr, &pEnd);
	return(*pEnd == 0);	
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


void display_data(std::map<std::string , float> dataBase)
{

	for (std::map<std::string, float>::iterator iter = dataBase.begin(); iter != dataBase.end(); ++iter) {
		std::cout << "Key: " << iter->first << ", Value: " << iter->second << std::endl;
	}
}

void bitcoinExchange(const std::string& inputFile)
{
	std::map<std::string , float> dataBase = importData();

	std::cout << "databasesuccessfully imported" << std::endl;
	
	evaluateInput(dataBase, inputFile);
	
	return ;
	//display_data(dataBase);
}

double	ft_strtod(const std::string& str)
{
	double result;

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

void evaluateInput(std::map<std::string , float> dataBase ,const std::string& inputFile)
{
	double value;
	std::vector<std::vector<std::string> > content = fileToVect(inputFile, '|');

	if (content.size() == 0 || content[0].size() != 2 || content[0][0] != "date" || content[0][1] != "exchange_rate")
	{
		std::cout << inputFile << ": input data base expect following format: date|value" << std::endl;
		throw(InvalidFormatException());		
	}	

	for(long unsigned int i=1; i < content.size(); i++)
	{
		if (content[i].size() != 2)
			std::cout << "Error: " << "line " << i << " should contain 2 elements." << std::endl;
		if (!isDateValid(content[i][0]))
			std::cout << "Error: " << "line " << i << " invalide date format. (" << content[i][0] << ")" << std::endl;
		if (!is_number(content[i][1]))
			std::cout << "Error: " << "line " << i << " value is not a number. (" << content[i][1] << ")" << std::endl;	
		value = ft_strtod(content[i][1]);
		if (value < 0 || value > 1000)
			std::cout << "Error: " << "line " << i << " values should be between 0 and 1000. (" << content[i][1] << ")" << std::endl;
		
		std::map<std::string, float>::iterator iter = dataBase.end();
		iter = dataBase.find(content[0][1]);
		if (iter == dataBase.end() && content[0][1] != iter->first)
			iter = dataBase.lower_bound(content[0][1]);
		if (iter == dataBase.end())
			std::cout << "Error: " << "line " << i << " no value have been found for this key. (" << content[i][0] << ")" << std::endl;
		else
			std::cout << content[i][0] << " => " << content[i][1] << " = " << value * iter->second << std::endl;	
	}
	return ;
}