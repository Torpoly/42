/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:36:56 by rpol              #+#    #+#             */
/*   Updated: 2023/02/15 15:21:55 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "Bureaucrat.hpp"

enum forms {

	PRESIDENTIAL_PARDON,
	ROBOTOMY_REQUEST,
	SHRUBBERY_CREATION	
};

class Intern {

	public:

		//canon
		Intern( void );
		Intern( const Intern & to_copy );
		Intern & operator=( const Intern & toTheRight );
		virtual ~Intern( void );

		
		AForm *	makeForm( std::string const form, std::string const target ) const;

	private:
	
		std::string const _printCreation( std::string const form, std::string const target ) const; 
};

#endif