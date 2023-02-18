/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:47:59 by rpol              #+#    #+#             */
/*   Updated: 2023/02/18 17:48:08 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// class Awsome {
	
// 	public :
// 	Awsome(void) : _n(42) {return;}
// 	int get(void) const {return this->_n;}
// 	private:
// 	int _n;
// };
// std::ostream & operator<<( std::ostream & o, Awsome const & rhs ) {o << rhs.get(); return o;}

// template< typename T >
// void	print( T const & x ) {

// 	std::cout << x << std::endl;
// 	return;
// }

int main( void ) {

	size_t size = 5;
	
	std::cout << std::endl;
	std::cout << "___PASSING__AN__INT__ARRAY_____" << std::endl << std::endl;

	int array[] = {1,2,3,4,5};
	iter( array, size, printIndex);
	

	std::cout << std::endl;
	std::cout << "___PASSING__A__STRING__ARRAY_____" << std::endl << std::endl;
	
	std::string Array[] = {"a","b","c","d","e"};
	iter( Array, size, printIndex);


	// std::cout << std::endl;
	// std::cout << "___PASSING__A__CLASS__ARRAY_____" << std::endl << std::endl;

	// Awsome tab[size];
	// iter( tab, size, print);

	std::cout << std::endl;
	
	return ( EXIT_SUCCESS );
}