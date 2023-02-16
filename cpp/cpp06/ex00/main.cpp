/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:36:42 by rpol              #+#    #+#             */
/*   Updated: 2023/02/16 17:17:17 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int main( int ac, char **av ) {

	if ( ac != 2 ) {
		
		std::cout << "Give me one argument ! (╯°□°)╯︵ ┻━┻ " << std::endl;
		return ( EXIT_FAILURE );
	}
	
	Conversion input( av[1] );
	
	input.printTheStuff();

	return( EXIT_SUCCESS );
}