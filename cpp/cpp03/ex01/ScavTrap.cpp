/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 01:11:28 by rpol              #+#    #+#             */
/*   Updated: 2023/02/09 17:11:31 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//canon
ScavTrap::ScavTrap( void ) : ClapTrap() {
	
	std::cout << "ScavTrap constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap( const ScavTrap & to_copy ) : ClapTrap( to_copy ) {

	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = to_copy; 
}

ScavTrap & 	ScavTrap::operator=( ScavTrap const & rhs ) {
	
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_energy_points = rhs._energy_points;
	this->_attack_damage = rhs._attack_damage;
	return ( *this );
}

ScavTrap::~ScavTrap( void ) {
	
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ) {

	std::cout << "ScavTrap naming constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

void	ScavTrap::attack( const std::string & target ) {

	if ( this->_hit_points == DEAD )
		std::cout << "ScavTrap " << this->_name << " can't attack because it's dead" << std::endl;
	else if ( this->_energy_points == DEAD )
		std::cout << "ScavTrap " << this->_name << " can't attack because it ran out of energy points" << std::endl;
	else
	{
		this->_energy_points--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attack_damage << " points of dammage !"<< std::endl;
		if (this->_energy_points == DEAD)
			std::cout << "ScavTrap " << this->_name << " is now out of energy !" << std::endl;
	}
}

void	ScavTrap::guardGate( void ) {
	if (this->_hit_points == DEAD)
		std::cout << "ScavTrap " << this->_name << " can't keep the gate because it's dead" << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " is now keeping the gate !" << std::endl;
}