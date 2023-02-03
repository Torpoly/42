/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 02:22:53 by rpol              #+#    #+#             */
/*   Updated: 2023/02/03 16:22:33 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) {

	return;
}

Harl::~Harl( void ) {

	return;
}
		
void	Harl::complain( std::string level ) {
	
	std::string lvl[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"};
	
	int HARL_LVL = DEBUG;
	while (HARL_LVL <= ERROR)
	{
		if (lvl[HARL_LVL] == level)
			break;
		HARL_LVL++;
	}
	
	switch (HARL_LVL) {
	
    	case DEBUG:
      		this->debug();
    	case INFO:
      		this->info();
   		case WARNING:
      		this->warning();
    	case ERROR:
     		this->error();
			break;
  		default:
      		std::cout << "Harl doesn't have a " << level << " level of complaint!" << std::endl;
      	return;
  	}
}

void Harl::debug( void ) {
	
	std::cout << "*DEBUG*" << std::endl;
	std::cout << "ChatGPT is slow. It's taking forever to process my request!" << std::endl;
}

void Harl::info( void ) {
	
	std::cout << "*INFO*" << std::endl;
	std::cout << "ChatGPT is inaccurate. It's not giving me the information I need." << std::endl;
}

void Harl::warning( void ) {
	
	std::cout << "*WARNING*" << std::endl;
	std::cout << "ChatGPT is unreliable. I can't trust the answers it gives me." << std::endl;
}

void Harl::error( void ) {
	
	std::cout << "*ERROR*" << std::endl;
	std::cout << "ChatGPT is completely broken. It's not working at all!" << std::endl;
}
