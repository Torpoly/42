/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 02:13:01 by rpol              #+#    #+#             */
/*   Updated: 2023/01/31 03:59:03 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact( void ) {
	
	is_set = false;
	
	return;
	
}

Contact::~Contact( void ) {
	
	return;
	
}

bool Contact::is_contact_set( void ) const {
	
	return (is_set);
	
}

void Contact::set_contact( int index ) {
	
	this->First_Name = "stuff";
	this->Last_Name = "stuff";
	this->Nickname = "stuff";
	this->Telephone_Number = "stuff";
	this->Darkest_Secret = "stuff";
	this->is_set = true;
	std::cout << "CONTACT INFO ADDED TO INDEX: " << index << " , GOING BACK TO MAIN MENU" << std::endl;
}

void Contact::print_contact_short( int index ) const {
	
	std::cout << index << " | ";
	
	std::cout << this->First_Name << " | ";
	
	std::cout << this->Last_Name << " | ";
	
	std::cout << this->Nickname << std::endl;
}
  
void Contact::print_contact_full( void ) const {
	
	std::cout << "FIRST NAME: " << this->First_Name << std::endl;
	
	std::cout << "LAST NAME: " << this->Last_Name << std::endl;
	
	std::cout << "NICKNAME: " << this->Nickname << std::endl;
	
	std::cout << "TELEPHONE NUMBER: " << this->Telephone_Number << std::endl;
	
	std::cout << "DARKEST SECRET: " << this->Darkest_Secret << std::endl;

	std::cout << "CONTACT INFO DISPLAYED, GOING BACK TO MAIN MENU" << std::endl;
}