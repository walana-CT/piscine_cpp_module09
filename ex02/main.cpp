/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:36:08 by rficht            #+#    #+#             */
/*   Updated: 2024/02/27 17:53:30 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"


bool isStrDigit(const char* str)
{
	while (*str)
		if (!isdigit(*str++))
			return false;
	return true;
}

void printInput(const std::vector<unsigned int>& input)
{
	int size = input.size();
	std::cout << "Before: ";	
	for (int i = 0; i < size && i < 10; i++)
		std::cout << input[i] << " ";
	if (size > 10)
		std::cout << "...";
	std::cout << std::endl;	
}


int main(int argc, char const *argv[])
{
	std::vector<unsigned int> vect, input;
	std::deque<unsigned int> deq;

	if (argc == 1)
		return 0;

	for (int i = 1; i < argc; i++)
	{
		if (!isStrDigit(argv[1]))
			return(std::cout << "please enter postive int only" << std::endl, 1);
		input.push_back(std::atoi(argv[i]));
	}
	
	printInput(input);
	
	std::vector<unsigned int> vect(input);
	std::deque<unsigned int> deq(input.begin(), input.end());

	
	

	return 0;
}
