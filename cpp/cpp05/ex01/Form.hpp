/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:20:03 by rpol              #+#    #+#             */
/*   Updated: 2023/02/14 22:43:50 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	public:

		//canon
		Form( void );
		Form( const Form & to_copy );
		Form & operator=( const Form & toTheRight );
		virtual ~Form( void );

		Form( std::string name, unsigned int _gradeToSign, unsigned int _gradeToExcute );

		
		std::string		getName( void ) const;

		bool			getIfSigned( void ) const;

		unsigned int	getGradeToSign( void ) const;

		unsigned int 	getGradeToExecute( void ) const;

		bool			beSigned( const Bureaucrat & bureaucratTringToSign );


		class GradeTooHighException : public std::exception {
			
			public:

				virtual const char* what( void ) const throw();

		};
		
		class GradeTooLowException : public std::exception {

			public:

				virtual const char* what( void ) const throw();

		};

	private:
	
		unsigned int		_isGoodGrade( unsigned int gradeTo );

		std::string const	_name;
		
		bool				_isSigned;
		
		unsigned int const	_gradeToSign;

		unsigned int const	_gradeToExecute;

};

/*IN Form.CPP*/

std::ostream & operator<<( std::ostream & o, Form const & toTheRight );

#endif