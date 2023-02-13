/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:59:29 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 02:43:36 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
	
	public:
	
		//canon
		Brain( void );
		Brain( const Brain & to_copy );
		Brain & operator=( const Brain & rhs );
		virtual ~Brain( void );
		
		void 				setIdea( unsigned int i, std::string idea );	
		
		const std::string getIdea( unsigned int i ) const;
	
	private:
	
		std::string _ideas[100];
	
};

#endif