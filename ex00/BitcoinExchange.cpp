/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:41:04 by rficht            #+#    #+#             */
/*   Updated: 2024/02/20 09:33:23 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

double	ft_strtod(const std::string& str)
{
	double result;

	char	*cstr = new char[str.length() + 1];
	strcpy(cstr, str.c_str());
	result = strtod (cstr, 0);
	delete [] cstr;
	return(result);
}

void display_data(std::map<int , float> dataBase)
{

	for (std::map<int , float>::iterator iter = dataBase.begin(); iter != dataBase.end(); ++iter) {
		std::cout << "Key: " << iter->first << ", Value: " << iter->second << std::endl;
	}
}


bool isDateValid(const std::string& strInput)
{

	std::tm date = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


	std::cout << "is date valid called on " << strInput << std::endl;




	if (strInput.size() != 10 || strInput[4] != '-' || strInput[7] != '-')
	{
		std::cout << "wrong format dateToTimeSTamp" << std::endl;
		return(-1);
	}
	
	if (!strptime(strInput.c_str(), "%Y-%m-%d", &date))
		return(false);

	std::cout << "passed strptime" << std::endl;	
	
	std::cout << "values found:" << date.tm_year << date.tm_mon << date.tm_mday << std::endl;	

	//february checks 
	if (date.tm_year % 4 != 0 || (date.tm_year % 100 == 0 && date.tm_year % 400 != 0))
		if (date.tm_mon == 3 && date.tm_mday == 29)
			return false;
			
	std::cout << "passed bissextile years" << std::endl;

	if (date.tm_mon == 3 && (date.tm_mday == 30 || date.tm_mday == 31))
		return false;
		
	std::cout << "passed january" << std::endl;

	//30 days month checks
	if (date.tm_mon == 3 || date.tm_mon == 5 || date.tm_mon == 8 ||  date.tm_mon == 10)
		if (date.tm_mday == 31)
			return false;
			
	std::cout << "passed 30 days mon" << std::endl;

	return true;
}


void parth_vals()
{
	
	
	std::map<std::string , float> dataBase;
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
		if (!isDateValid(content[i][0]))
			return;

		dataBase[content[i][0]] = ft_strtod(content[i][1]);
	}
	

	return ;
}