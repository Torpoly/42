/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 02:13:01 by rpol              #+#    #+#             */
/*   Updated: 2023/01/31 15:36:11 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
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
	
	std::cout<<"ENTER CONTACT FIRST NAME: ";
	while (std::getline(std::cin, this->First_Name) && this->First_Name == "\0")
		std::cout << "CAN'T HAVE EMPTY FIELD, PLEASE ENTER CONTACT FIRST NAME: ";

	std::cout<<"ENTER CONTACT LAST NAME: ";
	while (std::getline(std::cin, this->Last_Name) && this->Last_Name == "\0")
		std::cout << "CAN'T HAVE EMPTY FIELD, PLEASE ENTER CONTACT LAST NAME: ";

	std::cout<<"ENTER CONTACT NICKNAME: ";
	while (std::getline(std::cin, this->Nickname) && this->Nickname == "\0")
		std::cout << "CAN'T HAVE EMPTY FIELD, PLEASE ENTER CONTACT NICKNAME: ";

	std::cout<<"ENTER CONTACT TELEPHONE NUMBER: ";
	while (std::getline(std::cin, this->Telephone_Number) && this->Telephone_Number == "\0")
		std::cout << "CAN'T HAVE EMPTY FIELD, PLEASE ENTER CONTACT TELEPHONE NUMBER: ";

	std::cout<<"ENTER CONTACT DARKEST SECRET: ";
	while (std::getline(std::cin, this->Darkest_Secret) && this->Darkest_Secret == "\0")
		std::cout << "CAN'T HAVE EMPTY FIELD, PLEASE ENTER CONTACT DARKEST SECRET: ";
	
	this->is_set = true;
	std::cout << "CONTACT INFO ADDED TO INDEX: " << index << " , GOING BACK TO MAIN MENU" << std::endl;
}

void Contact::cut_string_10( std::string string) const {

	if (string.size() > 9)
		std::cout << string.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << string;
}

void Contact::print_contact_short( int index ) const {
	
	std::cout << std::setw(10) << index << "|";
	
	this->cut_string_10( this->First_Name );
	
	std::cout << "|";
	
	this->cut_string_10( this->Last_Name );

	std::cout << "|";

	this->cut_string_10( this->Nickname );
	
	std::cout << std::endl;
}
  
void Contact::print_contact_full( void ) const {
	
	std::cout << "FIRST NAME: " << this->First_Name << std::endl;
	
	std::cout << "LAST NAME: " << this->Last_Name << std::endl;
	
	std::cout << "NICKNAME: " << this->Nickname << std::endl;
	
	std::cout << "TELEPHONE NUMBER: " << this->Telephone_Number << std::endl;
	
	std::cout << "DARKEST SECRET: " << this->Darkest_Secret << std::endl;

	std::cout << "CONTACT INFO DISPLAYED, GOING BACK TO MAIN MENU" << std::endl;
}