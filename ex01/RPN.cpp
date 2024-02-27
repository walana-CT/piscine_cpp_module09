/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:47:35 by rficht            #+#    #+#             */
/*   Updated: 2024/02/27 09:53:57 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int popNbr(std::stack<int>& nbrStack)
{
	if (nbrStack.empty())
		throw(InvalidExprException());
	int result = nbrStack.top();
	nbrStack.pop();
	return (result);
}

bool isoperator(char c)
{
	if (c == '+' || c == '-' ||c == '*' ||c == '/' )
		return true;
	return false;		
}

void operatorExec(char c, std::stack<int>& nbrStack)
{
	int nbr2 = popNbr(nbrStack);
	int	nbr1 = popNbr(nbrStack);

	if (c == '+')
		nbrStack.push(nbr1 + nbr2);
	else if (c == '-')
		nbrStack.push(nbr1 - nbr2);
	else if (c == '*')
		nbrStack.push(nbr1 * nbr2);
	else if (c == '/')
	{
		if (nbr2 == 0)
			throw(DivByZeroException());
		nbrStack.push(nbr1 / nbr2);		
	}

	return;
}

void rpnStep(char* strInput, std::stack<int>& nbrStack)
{
	if (!strInput && !strInput[0])
		throw(InvalidExprException());

	if (isdigit(strInput[0]))
		nbrStack.push(strInput[0] - 48);
	else if(isoperator(strInput[0]))
		operatorExec(strInput[0], nbrStack);
		
	return;
}

int rpn(int argc, char *argv[])
{
	std::stack<int>		nbrStack;
	
	if (argc == 1)
		return(std::cout << std::endl, 0);	

	if (argc != 2)
		throw(TooManyArgsException());
	
	char* strInput = argv[1];

	while (*strInput)
	{
		rpnStep(strInput++, nbrStack);
		if (*strInput == ' ')
			strInput++;
	}

	int result = popNbr(nbrStack);
	
	if (nbrStack.empty())
		return(result);
	else
		throw(InvalidExprException());
		
	return 0;
}
