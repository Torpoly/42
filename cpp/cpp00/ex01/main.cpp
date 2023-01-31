/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:10:28 by rpol              #+#    #+#             */
/*   Updated: 2023/01/31 01:43:50 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main( void )
{
	PhoneBook PhoneBook;
	std::string command;
	
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "crappy awesome phonebook software started" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << " The program only accepts ADD | SEARCH | EXIT commands" << std::endl;
	std::cout << std::endl;
	while (1)
	{
		std::getline(std::cin, command);
		if (command == "ADD")
			PhoneBook.add();
		else if (command == "SEARCH")
			PhoneBook.search();
		else if (command == "EXIT")
			break;
	}
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "crappy awesome phonebook software terminated" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	return 0;
}
