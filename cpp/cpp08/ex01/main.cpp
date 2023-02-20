/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:25:40 by rpol              #+#    #+#             */
/*   Updated: 2023/02/20 18:17:50 by rpol             ###   ########.fr       */
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
	
	try {
		
		sp.addNumber(11);
		
    } catch ( const std::runtime_error & e ) {
		
        std::cerr << e.what() << std::endl;
    }



	std::cout << std::endl << "__PRINTING__INT__CONTAINER__" << std::endl << std::endl;
	
	sp.print();
	
	std::cout << std::endl;
	
	return ( EXIT_SUCCESS );
}