/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:18:46 by rpol              #+#    #+#             */
/*   Updated: 2023/02/15 02:47:26 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <cstdlib>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define HIGHEST_POSSIBLE_GRADE 1
#define LOWEST_POSSIBLE_GRADE 150

class Bureaucrat {

	public:

		//canon
		Bureaucrat( void );
		Bureaucrat( const Bureaucrat & to_copy );
		Bureaucrat & operator=( const Bureaucrat & toTheRight );
		virtual ~Bureaucrat( void );

		Bureaucrat( const std::string name, const unsigned int grade );


		void			incrementGrade( void );

		void			decrementGrade( void ); 

		unsigned int 	getGrade( void ) const;

		std::string		getName( void ) const;

		void			signForm( AForm & formToSign);

		void			execute( AForm const & form ) const;

		class GradeTooHighException : public std::exception {
			
			public:

				virtual const char* what(void) const throw();

		};
		
		class GradeTooLowException : public std::exception {

			public:

				virtual const char* what(void) const throw();

		};

	private:

		std::string const	_name;
		
		unsigned int		_grade;

};

/*IN BUREAUCRAT.CPP*/

std::ostream & operator<<( std::ostream & o, Bureaucrat const & toTheRight );

#endif