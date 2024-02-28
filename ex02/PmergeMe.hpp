/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:38:18 by rficht            #+#    #+#             */
/*   Updated: 2024/02/28 11:33:11 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <time.h>
#define N 20

template <typename T>
void printCont(const T input, int color)
{
	int size = input.size();

	if (color == 0)
		for (int i = 0; i < size && i < 10; i++)
			std::cout << input[i] << " ";
	else
		for (int i = 0; i < size && i < 10; i++)
			std::cout << "\u001b[48;5;" << i/2+color << "m " << input[i] << " ";
	if (size > 10)
		std::cout << "...";
	std::cout << "\u001b[0m" << std::endl;	
}

template <typename T>
void insertSort(T &c)
{
	unsigned int x, j, i =1;

	while (i < c.size())
	{
		x = c[i];
		j = i;
		while (j > 0 && c[j-1] > x)
		{
			c[j] = c[j-1];
			j--;		
		}		
		c[j] = x;
		i++;		
	}	
}

template <typename T>
void mergeSort(T &c)
{
	if (c.size() <= N)
		insertSort(c);
	else
	{

		typename T::iterator itMidle = c.begin();
		for (size_t i = 0; i < c.size()/2; i++)
			itMidle++;
		
		T c1 = T(c.begin(), itMidle);
		T c2 = T(itMidle, c.end());

		mergeSort(c1);
		mergeSort(c2);
		
		c.clear();

		std::merge(c1.begin(), c1.end(), c2.begin(), c2.end(), std::back_inserter(c));
	}
}

bool isStrDigit(const char* str);