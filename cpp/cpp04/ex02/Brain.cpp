/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:59:25 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 02:43:29 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//canon
Brain::Brain( void ) {
	
	std::cout << "Default Brain constructor called" << std::endl;
	return ;
}

Brain::Brain( const Brain & to_copy ) {

	std::cout << "Copy Brain constructor called" << std::endl;
	*this = to_copy;
	return ;
}

Brain & Brain::operator=( const Brain & rhs ) {
	
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = rhs._ideas[i];
	}
	return ( *this );
}

Brain::~Brain( void ) {

	std::cout << "Default Brain destructor called" << std::endl;
	return ;
}

void Brain::setIdea( unsigned int i, std::string idea ) {
	
	if (i < 100)
		this->_ideas[i] = idea;
	else
		std::cout << "Idea index must be 0-99, idea could not be set" << std::endl;
}
const std::string Brain::getIdea( unsigned int i ) const {

	if (i < 100)
		return ( this->_ideas[i] );
	std::string str = "Idea index must be 0-99";
	return ( str );
}
