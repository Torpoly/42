/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:39:09 by rpol              #+#    #+#             */
/*   Updated: 2023/02/02 00:22:39 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( void ) {
	
	return;
}
Zombie::~Zombie( void ) {
	
	std::cout << "Zombie: " << this->_name << " has died" << std::endl;
	return;
}
		
void Zombie::announce( void ){
	
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::name_zombie( std::string name ){
	
	this->_name = name;
	std::cout << "Zombie: " << this->_name << " has been named" << std::endl;
}