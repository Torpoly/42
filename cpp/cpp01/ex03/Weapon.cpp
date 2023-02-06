/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:09:04 by rpol              #+#    #+#             */
/*   Updated: 2023/02/06 18:20:23 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type) {
	
	return ;
}

Weapon::~Weapon( void ){
	
	return ;
}

std::string 	Weapon::getType( void ) const {
	
	return ( this->_type );
}
		
void 			Weapon::setType( std::string type ) {
	
	if (type.empty())
		this->_type = "A WEAPON THAT IS NAMED EMPTY STRING";
	else
		this->_type = type;
}