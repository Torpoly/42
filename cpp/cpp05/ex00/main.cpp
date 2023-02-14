/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:18:50 by rpol              #+#    #+#             */
/*   Updated: 2023/02/14 20:08:41 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main ( void ) {

	Bureaucrat Ron("Ron ", 2);

	std::cout << Ron << std::endl;
	Ron.incrementGrade();
	std::cout << Ron << std::endl;
	Ron.incrementGrade();
	std::cout << Ron << std::endl;

	std::cout << std::endl;

	Bureaucrat Andy("Andy", 149);

	std::cout << Andy << std::endl;
	Andy.decrementGrade();
	std::cout << Andy << std::endl;
	Andy.decrementGrade();
	std::cout << Andy << std::endl;

	std::cout << std::endl;
	
	Bureaucrat Leslie("Leslie", 0);

	std::cout << Leslie << std::endl;

	std::cout << std::endl;

	Bureaucrat April("April", 151);

	std::cout << April << std::endl;
	
	return ( EXIT_SUCCESS );
}