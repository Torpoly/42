/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:29:00 by rpol              #+#    #+#             */
/*   Updated: 2023/02/15 02:06:10 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

#define ROBOTOMY_GRADE_TO_SIGN 72
#define ROBOTOMY_GRADE_TO_EXECUTE 45

class RobotomyRequestForm : public AForm {

	public:

		//canon
		RobotomyRequestForm( void );
		RobotomyRequestForm( const RobotomyRequestForm & to_copy );
		RobotomyRequestForm & operator=( const RobotomyRequestForm & toTheRight );
		virtual ~RobotomyRequestForm( void );

		RobotomyRequestForm( std::string target );
		
		std::string		getTarget( void ) const;
		
	private:

		void				_executeAction( void ) const;
	
		const std::string	_target;

};

/*IN ROBOTOMYREQUESTFORM_.CPP*/

std::ostream & operator<<( std::ostream & o, RobotomyRequestForm const & toTheRight );

#endif