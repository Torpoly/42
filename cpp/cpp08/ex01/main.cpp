/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:25:40 by rpol              #+#    #+#             */
/*   Updated: 2023/02/20 22:52:53 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main( void ) {
	
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	
	std::cout << std::endl << "__PRINTING__INT__CONTAINER__" << std::endl << std::endl;
	
	sp.print();
	
	
	
	std::cout << std::endl << "__PRINTING__SHORTEST__SPAN__" << std::endl << std::endl;
	
	std::cout << std::endl << sp.shortestSpan() << std::endl;



	std::cout << std::endl << "__PRINTING__LONGEST__SPAN__" << std::endl << std::endl;
	
	std::cout << std::endl << sp.longestSpan() << std::endl;
	
	
	
	std::cout << std::endl << "__TRYING__TO__ADD__EXTRA__NUMBER__IN__CONTAINER__" << std::endl << std::endl;

	sp.addNumber(11);



	std::cout << std::endl << "__PRINTING__INT__CONTAINER__" << std::endl << std::endl;
	
	sp.print();

	std::cout << std::endl;

	Span sr = Span(10);

	sr.addRange( 5, -4 );

	std::cout << std::endl;

	sr.print();
	
	std::cout << std::endl;
	
	return ( EXIT_SUCCESS );
}