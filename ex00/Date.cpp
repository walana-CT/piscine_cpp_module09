/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:46:54 by rficht            #+#    #+#             */
/*   Updated: 2024/01/31 11:06:34 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Date.hpp"

const int& Date::getYear() const
{	return(this->year);	}


const int& Date::getMonth() const
{	return(this->month);	}

const int& Date::getDay() const
{	return(this->day);	}

Date::Date()
{}

Date::Date(const int & year, const int & month, const int & day) : year(year), month(month), day(day)
{}

Date::Date(const Date& rhs)
{	*this = rhs;	}

Date::~Date()
{}

const Date& Date::operator = (const Date& rhs)
{
	this->year = rhs.getYear();
	this->month = rhs.getMonth();
	this->day = rhs.getDay();

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
		os << date.getYear() << '-' << date.getMonth() << '-' << date.getDay();
	return os;
}