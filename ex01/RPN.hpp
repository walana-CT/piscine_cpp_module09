/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:47:38 by rficht            #+#    #+#             */
/*   Updated: 2024/02/27 16:38:45 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <iostream>

class TooManyArgsException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{	return ("Error: rpn expect 1 argument.");	}
};

class InvalidExprException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{	return ("Error: rpn ecountered invalid synthax while reading.");	}
};

class DivByZeroException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{	return ("Error: division by zero.");	}
};

int rpn(int argc, char *argv[]);
