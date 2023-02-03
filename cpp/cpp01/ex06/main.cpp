/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 02:23:02 by rpol              #+#    #+#             */
/*   Updated: 2023/02/03 15:08:08 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main( void ) {

	Harl harl;

	harl.complain("DEBUG");
	
	std::cout << std::endl;

	harl.complain("INFO");

	std::cout << std::endl;

	harl.complain("WARNING");

	std::cout << std::endl;

	harl.complain("ERROR");

	std::cout << std::endl;

	harl.complain("UNKNOWNED");

	return EXIT_SUCCESS;
}