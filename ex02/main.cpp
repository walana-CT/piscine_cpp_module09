/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:36:08 by rficht            #+#    #+#             */
/*   Updated: 2024/03/01 08:54:28 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

int main(int argc, char const *argv[])
{
	std::vector<unsigned int> input;
	clock_t time;
	int mult = 2;

	if (argc == 1)
		return 0;

	std::cout << std::endl;

	for (int i = 1; i < argc; i++)
	{
		if (!isStrDigit(argv[1]))
			return(std::cout << "please enter postive int only" << std::endl, 1);
		for (int j = 0; j < mult; j++)
			input.push_back(std::atoi(argv[i]) + j);
	}
	
	std::cout << "\u001b[1m \u001b[4m INPUT: \u001b[0m" << std::endl;		
	printCont(input, 0);
	std::cout << "smallest group elem:" << N << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "\u001b[1m \u001b[4m Vector: \u001b[0m" << std::endl;	

	//VECTOR
	std::vector<unsigned int> vect(input);
	time = clock();
	mergeSort(vect);
	time = clock() - time;
	std::cout << "computation time: " << "\u001b[38;5;" << 202 << "m " << ((float)time/CLOCKS_PER_SEC) << "seconds \u001b[0m" << std::endl;
	printCont(vect, 202);
	std::cout << std::endl << std::endl;

	//DEQUE
	std::cout << "\u001b[1m \u001b[4m Deque: \u001b[0m" << std::endl;
	std::deque<unsigned int> deq(input.begin(), input.end());
	time = clock();	
	mergeSort(deq);
	time = clock() - time;
	std::cout << "computation time: " << "\u001b[38;5;" << 160 << "m " << ((float)time/CLOCKS_PER_SEC) << "seconds \u001b[0m" << std::endl;	
	printCont(deq, 88);
	std::cout << std::endl;

	return 0;
}
