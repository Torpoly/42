/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:28:51 by rpol              #+#    #+#             */
/*   Updated: 2023/02/15 02:00:52 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

#define PRESIDENTIAL_GRADE_TO_SIGN 25
#define PRESIDENTIAL_GRADE_TO_EXECUTE 5

class PresidentialPardonForm : public AForm {

	public:

		//canon
		PresidentialPardonForm( void );
		PresidentialPardonForm( const PresidentialPardonForm & to_copy );
		PresidentialPardonForm & operator=( const PresidentialPardonForm & toTheRight );
		virtual ~PresidentialPardonForm( void );

		PresidentialPardonForm( std::string target );
		
		std::string		getTarget( void ) const;
		
	private:

		void				_executeAction( void ) const;
	
		const std::string	_target;

};

/*IN PRESIDENTIALPARDONFORM.CPP*/

std::ostream & operator<<( std::ostream & o, PresidentialPardonForm const & toTheRight );

#endif