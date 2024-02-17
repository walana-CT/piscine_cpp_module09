/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:41:04 by rficht            #+#    #+#             */
/*   Updated: 2024/02/17 14:29:06 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


std::time_t dateToTimestamp(const std::string& strInput)
{
	char	yearStr[5];
	char	monthStr[3];
	char	dayStr[3];

	if (strInput.size() != 10 || strInput[4] != '-' || strInput[7] != '-')
	{
		std::cout << "wrong format dateToTimeSTamp" << std::endl;
		return(-1);
	}
	
	for (size_t i = 0; i < 4; i++)
	{
		if (!isdigit(strInput[i]))
			return(-1);
		yearStr[i] = strInput[i]; 		
	}
	yearStr[4] = 0;
	for (size_t i = 0; i < 2; i++)
	{
		if (!isdigit(strInput[i+5]))
			return(-1);
		yearStr[i] = strInput[i+5]; 		
	}
	monthStr[2] = 0;	
	for (size_t i = 0; i < 2; i++)
	{
		if (!isdigit(strInput[i+8]))
			return(-1);
		yearStr[i] = strInput[i+8]; 		
	}
	dayStr[2] = 0;
	std::tm date = {0};
	date.tm_year = 1900 - atoi(yearStr);
	date.tm_mon = atoi(monthStr);
	date.tm_mday = atoi(dayStr);
	return (std::mktime(&date));
}



void parth_vals()
{
	
	
	std::map<int , float> dataBase;
	std::vector<std::vector<std::string> > content;
	std::vector<std::string> row;
	std::string line, word;
	std::fstream file ("data.csv", std::ios::in);
	if(file.is_open())
	{
		std::cout << "file opened successfullly" << std::endl;
		while(getline(file, line))
		{
			row.clear();
			std::stringstream str(line);
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
	{
		std::cout<<"Could not open the file\n";
	}
	

	if (content[0].size() != 2 || content[0][0] != "date" || content[0][1] != "exchange_rate")
		std::cout << "data base should be at the following format: date,exchange_rate";
	std::cout << content[0].size() << std::endl;



	//for(long unsigned int i=1; i < content.size(); i++)
	for(long unsigned int i=1; i < 10; i++)
	{
		size_t pos = 0;
		char	*cstr = new char[content[i][1].length() + 1];
		strcpy(cstr, content[i][1].c_str());
		dataBase[dateToTimestamp(content[i][0])] = strtod (cstr, 0);
		std::cout<< std::endl ;
	}

	return ;
}