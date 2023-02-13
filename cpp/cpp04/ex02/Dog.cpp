/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:20:26 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 03:43:39 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//canon
Dog::Dog( void ) : AAnimal() {

std::cout << "Default Dog constructor called" << std::endl;
	this->_type = "Dog";
	this->_Brain = new Brain();
	return ;
}

Dog::Dog( const Dog & to_copy ) : AAnimal( to_copy ) {

	std::cout << "Copy Dog constructor called" << std::endl;
	this->_Brain = new Brain();
	*this = to_copy;
}

Dog & Dog::operator=( const Dog & rhs ) {
	
	this->_type = rhs._type;
	for (int i = 0; i < 100; i++)
	{
		this->_Brain->setIdea( i, rhs._Brain->getIdea( i ) );
	}
	return ( *this ); 
}

Dog::~Dog( void ) {

	std::cout << "Default Dog destructor called" << std::endl;
	delete this->_Brain;
	return ;
}

void	Dog::makeSound( void ) const {
	
	std::cout << "* ˁ˚ᴥ˚ˀ Wouaf *" << std::endl;
}

const	std::string & Dog::getType( void ) const {
	
	return ( this->_type );
}

void	Dog::setIdea( unsigned int i, std::string idea ) {

	this->_Brain->setIdea( i, idea );
}
		
const	std::string Dog::getIdea( unsigned int i ) const {
	
	if ( this->_Brain->getIdea( i ).empty() )
		return ( "empty * ˁ˚ᴥ˚ˀ Wouaf * idea" );
	return ( this->_Brain->getIdea( i ) );
}

void	Dog::printBrainAdresse( void ) const {

	std::cout << this->_Brain << std::endl;
}
