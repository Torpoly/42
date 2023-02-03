/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:09:04 by rpol              #+#    #+#             */
/*   Updated: 2023/02/02 22:48:01 by rpol             ###   ########.fr       */
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
	
	this->_type = type;
}