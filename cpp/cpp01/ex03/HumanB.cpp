/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:13:42 by rpol              #+#    #+#             */
/*   Updated: 2023/02/02 23:00:37 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name( name ) {
	
	this->_name_of_weapon = NULL;
	return ;
}
		
HumanB::~HumanB( void ) {
	
	return ;
}

		
void 		HumanB::attack( void ) const {

	if (this->_name_of_weapon)
		std::cout << this->_name << " attacks with their " << this->_name_of_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " can't attack he doesn't have a weapon..." << std::endl;
		
}

void		HumanB::setWeapon( Weapon&  name_of_weapon) {
	
	this->_name_of_weapon = &name_of_weapon;
}