/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:39:09 by rpol              #+#    #+#             */
/*   Updated: 2023/02/01 23:10:13 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( std::string name ) {
	
	this->_name = name;
}
Zombie::~Zombie( void ) {
	std::cout << this->_name << " has been destroyed!" << std::endl;
}
		
void Zombie::announce( void ){
	
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}