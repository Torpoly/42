/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:00:50 by rpol              #+#    #+#             */
/*   Updated: 2023/02/09 18:15:00 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//canon
FragTrap::FragTrap( void ) : ClapTrap() {
	
	std::cout << "FragTrap constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap( const FragTrap & to_copy ) : ClapTrap( to_copy ) {

	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = to_copy; 
}

FragTrap & 	FragTrap::operator=( FragTrap const & rhs ) {
	
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_energy_points = rhs._energy_points;
	this->_attack_damage = rhs._attack_damage;
	return ( *this );
}

FragTrap::~FragTrap( void ) {
	
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name ) {

	std::cout << "FragTrap naming constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

void	FragTrap::highFivesGuys( void ) {
	if (this->_hit_points == DEAD)
		std::cout << "FragTrap " << this->_name << " can't display a positive high fives request because it's dead" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " displays a positive high fives request !" << std::endl;
}