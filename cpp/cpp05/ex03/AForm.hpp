/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:20:03 by rpol              #+#    #+#             */
/*   Updated: 2023/02/15 01:30:51 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	public:

		//canon
		AForm( void );
		AForm( const AForm & to_copy );
		AForm & operator=( const AForm & toTheRight );
		virtual ~AForm( void );

		AForm( std::string name, unsigned int _gradeToSign, unsigned int _gradeToExcute );

		
		std::string		getName( void ) const;

		bool			getIfSigned( void ) const;

		unsigned int	getGradeToSign( void ) const;

		unsigned int 	getGradeToExecute( void ) const;

		bool			beSigned( const Bureaucrat & bureaucratTringToSign );

		bool			execute(Bureaucrat const & executor) const;

		class GradeTooHighException : public std::exception {
			
			public:

				virtual const char* what( void ) const throw();

		};
		
		class GradeTooLowException : public std::exception {

			public:

				virtual const char* what( void ) const throw();

		};
		
		class FormNotSignedException : public std::exception {

			public:

				virtual const char* what( void ) const throw();

		};

	protected:

		virtual void		_executeAction( void ) const = 0;
	
		unsigned int		_isGoodGrade( unsigned int gradeTo );

		std::string const	_name;
		
		bool				_isSigned;
		
		unsigned int const	_gradeToSign;

		unsigned int const	_gradeToExecute;

};

/*IN AForm.CPP*/

std::ostream & operator<<( std::ostream & o, AForm const & toTheRight );

#endif