/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:32:56 by rpol              #+#    #+#             */
/*   Updated: 2023/02/07 16:15:52 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) {
	
	std::cout << "ClapTrap constructor called" << std::endl;
	this->_name = "steve";
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
}

ClapTrap::ClapTrap( std::string name ) {

	std::cout << "ClapTrap naming constructor called" << std::endl;
	this->_name = name;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
}
ClapTrap::ClapTrap( const ClapTrap & src ) {

	std::cout << "ClapTrap copy constructor called" << std::endl;
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
}
ClapTrap::~ClapTrap( void ) {
	
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap & 	ClapTrap::operator=( ClapTrap const & rhs ) {
	
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_energy_points = rhs._energy_points;
	this->_attack_damage = rhs._attack_damage;
	return ( *this );
}
void		ClapTrap::attack(const std::string& target) {

	if ( this->_hit_points == DEAD )
		std::cout << "ClapTrap " << this->_name << " can't attack because it's dead" << std::endl;
	else if ( this->_energy_points == DEAD )
		std::cout << "ClapTrap " << this->_name << " can't attack because it ran out of energy points" << std::endl;
	else
	{
		this->_energy_points--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attack_damage << " points of dammage !"<< std::endl;
		if (this->_energy_points == DEAD)
			std::cout << "ClapTrap " << this->_name << " is now out of energy !" << std::endl;
	}
}
void 		ClapTrap::takeDamage(unsigned int amount) {
	
	if ( this->_hit_points == DEAD )
		std::cout << "ClapTrap " << this->_name << " can't take damage because it's dead" << std::endl;
	else
	{
		if (this->_hit_points < (int)amount)
			this->_hit_points = 0;
		else
			this->_hit_points -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage points, is now at " << this->_hit_points << " hit points !"<< std::endl;
		if (this->_hit_points == DEAD)
			std::cout << "ClapTrap " << this->_name << " is now dead !" << std::endl;
	}
}
void 		ClapTrap::beRepaired(unsigned int amount) {
	
	if ( this->_hit_points == DEAD )
		std::cout << "ClapTrap " << this->_name << " can't repair because it's dead" << std::endl;
	else if ( this->_energy_points == DEAD )
		std::cout << "ClapTrap " << this->_name << " can't repair because it ran out of energy points" << std::endl;
	else
	{
		this->_energy_points--;
		if ( (this->_hit_points + amount) >= 100 )
			this->_hit_points = 100;
		else
			this->_hit_points += amount;
		std::cout << "ClapTrap " << this->_name << " repairs by " << amount << " points, is now at " << this->_hit_points << " hit points !"<< std::endl;
		if (this->_energy_points == DEAD)
			std::cout << "ClapTrap " << this->_name << " is now out of energy !" << std::endl;
	}
}