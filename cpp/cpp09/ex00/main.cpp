/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:43:39 by rpol              #+#    #+#             */
/*   Updated: 2023/03/27 16:05:35 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// test.txt

// date | value
// 2011-01-03 | 3
// 2011-01-03 | 2
// 2011-01-03 | 1
// 2011-01-03 | 1.2
// tamere
// 2011-01-09 | 1
// 2012-01-11 | -1
// 2001-42-42
// 2012-01-11 | 1
// 2012-01-11 | 2147483648
// 2001-01-11 | 21
// 2009-01-01 | 21
// 2009-01-02 | 21
// 2023-03-30 | 3
// 2022-04-31 | 3
// 2023-03-20 | 3
// 2024-03-20 | 3
// 2010-11-16 | 10 

#include "BitcoinExchange.hpp"

#include <sys/stat.h>
bool is_a_directory( std::string file_name ) {
	
    struct stat buffer;
    int status = stat(file_name.c_str(), &buffer);
    if (status == 0 && !(buffer.st_mode & S_IFDIR))
        return false;
    else
		return true;
}

int main(int argc, char **argv) {
	
    if (argc != 2) {
		
        if ( argc > 2 )
            std::cout << "Error: Invalid number of arguments. Usage: ./btc <file>" << std::endl;
        else
            std::cout << "Error: could not open file." << std::endl;
        return EXIT_FAILURE;
    }

    BitcoinExchange btcExchange;

    try {

        btcExchange.readFile("data.csv");
        btcExchange.processData(argv[1]);
    } catch (const std::runtime_error& e) {
		
        std::cout << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    

    return EXIT_SUCCESS;
}