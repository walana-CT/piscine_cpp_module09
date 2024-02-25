/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:05:21 by rficht            #+#    #+#             */
/*   Updated: 2024/02/25 10:17:02 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"BitcoinExchange.hpp"


int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "error: btc: takes 1 argument" << std::endl;
		return 1;
	}
	
	try	
	{	bitcoinExchange(argv[1]);	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	
	return 0;
}


