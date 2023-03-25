/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:43:30 by rpol              #+#    #+#             */
/*   Updated: 2023/03/25 01:03:32 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		bool readFile( const std::string &filename );
		void processData( const std::string &inputFile );
		bool isValidInput( const std::string &line, std::string &date, double &value );

	private:
	
		std::vector<std::pair<std::string, double> > _historical_prices;
};
