/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:12:38 by rpol              #+#    #+#             */
/*   Updated: 2023/01/30 20:16:28 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {
	
	std::cout << "constructor called" << std::endl;
	
	return;
	
}
PhoneBook::~PhoneBook( void ) {

	std::cout << "destructor called" << std::endl;
	
	return;
	
}