/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:20:20 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 03:10:11 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//canon
Cat::Cat( void ) : Animal() {

	std::cout << "Default Cat constructor called" << std::endl;
	this->_type = "Cat";
	this->_Brain = new Brain();
	return ;
}

Cat::Cat( const Cat & to_copy ) : Animal( to_copy ) {
	
	std::cout << "Copy Cat constructor called" << std::endl;
	this->_Brain = new Brain( *to_copy._Brain );
	*this = to_copy;
}

Cat & Cat::operator=( const Cat & rhs ) {
	
	this->_type = rhs._type;
	for (int i = 0; i < 100; i++)
	{
		this->_Brain->setIdea( i, rhs._Brain->getIdea( i ) );
	}
	return ( *this ); 
}

Cat::~Cat( void ) {

	std::cout << "Default Cat destructor called" << std::endl;
	delete this->_Brain;
	return ;
}

void	Cat::makeSound( void ) const {
	
	std::cout << "* =^..^= Miaou *" << std::endl;
}

void	Cat::setIdea( unsigned int i, std::string idea ) {

	this->_Brain->setIdea( i, idea );
}
		
const	std::string Cat::getIdea( unsigned int i ) const {

	return ( this->_Brain->getIdea( i ) );
}

void	Cat::printBrainAdresse( void ) const {

	std::cout << this->_Brain << std::endl;
}
