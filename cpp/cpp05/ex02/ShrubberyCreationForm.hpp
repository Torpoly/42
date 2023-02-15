/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:29:08 by rpol              #+#    #+#             */
/*   Updated: 2023/02/15 02:50:31 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

#define SHRUBBERY_GRADE_TO_SIGN 145
#define SHRUBBERY_GRADE_TO_EXECUTE 137

class ShrubberyCreationForm : public AForm {

	public:

		//canon
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm & to_copy );
		ShrubberyCreationForm & operator=( const ShrubberyCreationForm & toTheRight );
		virtual ~ShrubberyCreationForm( void );

		ShrubberyCreationForm( std::string target );
		
		std::string		getTarget( void ) const;
		
	private:

		void				_executeAction( void ) const;
	
		const std::string	_target;

};

/*IN SCHRUBBERYCREATIONFORM.CPP*/

std::ostream & operator<<( std::ostream & o, ShrubberyCreationForm const & toTheRight );

#endif