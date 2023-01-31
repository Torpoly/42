/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:12:38 by rpol              #+#    #+#             */
/*   Updated: 2023/01/31 04:01:44 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook( void ) {
	
	this->contact_index = 0;

	this->first_contact_added = false;

	this->max_contact_reached = false;

	Contact contact1;

	Contact contact2;
	
	Contact contact3;
	
	Contact contact4;
	
	Contact contact5;
	
	Contact contact6;
	
	Contact contact7;
	
	Contact contact8;
	
	this->Contact_Tab[0] = contact1;

	this->Contact_Tab[2] = contact2;
	
	this->Contact_Tab[3] = contact3;
	
	this->Contact_Tab[4] = contact4;
	
	this->Contact_Tab[5] = contact5;
	
	this->Contact_Tab[5] = contact6;
	
	this->Contact_Tab[6] = contact7;
	
	this->Contact_Tab[7] = contact8;
	
	return;
	
}
PhoneBook::~PhoneBook( void ) {
	
	return;
	
}

void PhoneBook::add( void ) {

	this->Contact_Tab[this->contact_index].set_contact(this->contact_index + 1);
	this->contact_index++;
	this->first_contact_added = true;
	if (this->contact_index > 7)
	{
		this->max_contact_reached = true;
		std::cout << "MAX STORAGE CAPACITY OF 8 CONTACTS REACHED !" << std::endl;
		std::cout << "NEXT ADDED CONTACTS WILL OVERWRITE OLDESTS ONES" << std::endl;
		this->contact_index = 0;
	}
	
	
	return;
	
}

void PhoneBook::search( void ) {

	if (this->first_contact_added == false)
		std::cout << "NO CONTACT IN DATABASE, GOING BACK TO MAIN MENU" << std::endl;
	else
	{
		int index = 0;
		while (index < 8)
		{
			if (this->Contact_Tab[index].is_contact_set()) 
				this->Contact_Tab[index].print_contact_short(index + 1);
			index++;
		}
		index = 0 ;
		std::cout << "ENTER INDEX OF CONTACT YOU WANT INFO DISPLAYED" << std::endl;
		std::cout << "CONTACT INDEX: ";
		std::cin >> index;
		if (index > 0 && index < 9)
		{
			if (this->Contact_Tab[index - 1].is_contact_set())
			{
				this->Contact_Tab[index - 1].print_contact_full();
				return;
			}
			else
					std::cout << "WRONG INDEX, GOING BACK TO MAIN MENU" << std::endl;
		}
		else
			std::cout << "WRONG INDEX, GOING BACK TO MAIN MENU" << std::endl;
		std::cin.clear();
		
	}
	
	return;
	
}