/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:40:49 by rficht            #+#    #+#             */
/*   Updated: 2024/02/25 10:31:00 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include"btcUtils.hpp"

std::map<std::string, float>	importData();
void	evaluateInput(std::map<std::string, float> dataBase ,const std::string& inputFile);
void	bitcoinExchange(const std::string& inputFile);

#endif
