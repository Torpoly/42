/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:43:39 by rpol              #+#    #+#             */
/*   Updated: 2023/03/27 00:20:43 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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