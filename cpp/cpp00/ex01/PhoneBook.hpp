/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:50:19 by rpol              #+#    #+#             */
/*   Updated: 2023/01/31 02:50:44 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

public:
	
	PhoneBook( void );
	~PhoneBook( void );
	
	void add( void );
	
	void search( void );
	
private:

	int contact_index;
	
	bool first_contact_added;

	bool max_contact_reached;
	
	Contact Contact_Tab[8];

};

#endif