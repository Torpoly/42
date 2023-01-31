/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:50:57 by rpol              #+#    #+#             */
/*   Updated: 2023/01/31 15:04:18 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {

public:

	Contact( void );	
	~Contact( void );

	void set_contact( int index );

	void print_contact_full( void ) const;

	void print_contact_short( int index ) const;

	void cut_string_10( std::string string) const;

	bool is_contact_set( void ) const;

private:
	bool is_set;

	std::string First_Name;
	
	std::string Last_Name;
	
	std::string Nickname;
	
	std::string Telephone_Number;
	
	std::string Darkest_Secret;
};

#endif
