/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:38:18 by rficht            #+#    #+#             */
/*   Updated: 2024/02/27 18:20:15 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 40


template <typename T>
T insertSort(T c)
{
    int i, key, j;
    for (i = 1; i < n; i++) 
	{
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
		{
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
	
}

template <typename T>
T mergeSort(T &c)
{
	if (c.size() <= N)
		insertSort(c);
	else
	{
		T c1 = T(c.begin(), c.end()/2);
		T c2 = T(c.end()/2, c.end());

		mergeSort(c1);
		mergeSort(c2);
		
		c.clear();

		std::merge(c1.begin(), c1.end(), c2.begin(), c2.end(), c.begin());
	}
}