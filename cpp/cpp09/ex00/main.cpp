/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:43:39 by rpol              #+#    #+#             */
/*   Updated: 2023/03/24 23:42:37 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	
    if (argc != 2) {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        return EXIT_FAILURE;
    }

    BitcoinExchange btcExchange;

    if (!btcExchange.readFile("data.csv")) {
        std::cerr << "Error: could not open data.csv." << std::endl;
        return EXIT_FAILURE;
    }

    btcExchange.processData(argv[1]);

    return EXIT_SUCCESS;
}