/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:43:30 by rpol              #+#    #+#             */
/*   Updated: 2023/03/27 00:20:46 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>

class BitcoinExchange {
	
	public:
		
		//////// Orthodox Canonical Form /////////
		BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange &toCopy );
		BitcoinExchange& operator=(const BitcoinExchange &toTheRight);
		~BitcoinExchange( void );
		
		/////// METHODS /////////
		void readFile( const std::string &filename );
		void processData( const std::string &inputFile );
		bool isValidInput( const std::string &line, std::string &date, double &value );

	private:
	
		std::vector<std::pair<std::string, double> > _historical_prices;
};

#endif
