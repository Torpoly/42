/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:21:09 by rpol              #+#    #+#             */
/*   Updated: 2023/02/17 15:51:52 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int getRandomBase() {
	
    srand(time(NULL));
    return ( rand() % 3 );
}

Base*	generate( void ) {
	
	switch ( getRandomBase() ) {
	
		case BASE_A:
			
			return ( new A() );
		
		case BASE_B:
			
			return ( new B() );
		
		case BASE_C:
			
			return ( new C() );

	default:
		
		std::cout << "Something went wrong in the probability realm !" << std::endl;
		return ( new A() );
	}
}

void identify( Base& p ) {
	
	try {
		
		A& base = dynamic_cast< A & >( p );
		static_cast< void >( base );
		std::cout << "the base ref p is an instance of A" << std::endl << std::endl;
		return;

	} catch (std::exception& bad_cast_e) {
		
	}
	try {
		
		B& base = dynamic_cast< B & >( p );
		static_cast< void >( base );
		std::cout << "the base ref p is an instance of B" << std::endl << std::endl;
		return;

	} catch (std::exception& bad_cast_e) {
		
	}
	try {
		
		C& base = dynamic_cast< C & >( p );
		static_cast< void >( base );
		std::cout << "the base ref p is an instance of C" << std::endl << std::endl;
		return;

	} catch (std::exception& bad_cast_e) {
		
	}
	
	std::cout << "the base ref p is not an instance of A, B or C !" << std::endl << std::endl;
	return;
}

void identify( Base* p ) {
	
	if ( dynamic_cast< A * >( p ) ) {
		
		std::cout << "the base ptr p is an instance of A" << std::endl << std::endl;
	
	} else if ( dynamic_cast< B * >( p ) ) {
	
		std::cout << "the base ptr p is an instance of B" << std::endl << std::endl;
	
	} else if ( dynamic_cast< C * >( p ) ) {
	
		std::cout << "the base ptr p is an instance of C" << std::endl << std::endl;
	
	} else {
		
		std::cout << "the base ptr p is not an instance of A, B or C !" << std::endl << std::endl;
	}
}

int	main( void ) {
	
	std::cout << std::endl;
	std::cout << "_______GENERATE_RANDOM_BASE________" << std::endl << std::endl;
	
	Base* base = generate();

	std::cout << "_______IDENTIFY_WITH_PTR________" << std::endl << std::endl;

	identify(base);

	std::cout << "_______IDENTIFY_WITH_REF________" << std::endl << std::endl;

	identify(*base);
	
	delete base;

	std::cout << std::endl;
	std::cout << "_______GENERATE_WRONG_BASE________" << std::endl << std::endl;
	Base* wrongBase = new Base();

	std::cout << "_______WRONG_IDENTIFY_WITH_PTR________" << std::endl << std::endl;

	identify(wrongBase);

	std::cout << "_______WRONG_IDENTIFY_WITH_REF________" << std::endl << std::endl;

	identify(*wrongBase);
	
	delete wrongBase;
	
	return ( EXIT_SUCCESS );
}