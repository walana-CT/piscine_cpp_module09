/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:46:57 by rficht            #+#    #+#             */
/*   Updated: 2024/01/31 11:06:18 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Date
{
private:
	int year;
	int month;
	int day;
	
public:
	Date();
	Date(const int & year, const int & month, const int & day);
	Date(const Date& rhs);
	~Date();

	const Date& operator = (const Date& rhs);

	const int& getYear() const;
	const int& getMonth() const;
	const int& getDay() const;
};


std::ostream& operator<<(std::ostream& os, const Date& dt);


