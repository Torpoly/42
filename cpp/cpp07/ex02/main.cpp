/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:47:59 by rpol              #+#    #+#             */
/*   Updated: 2023/02/19 13:18:28 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>
#include <ctime>



int main( void ) {

    size_t size = 10;
    
	std::cout << "_______ARRAY__<_INT_>__________" << std::endl << std::endl;
	
    Array<int> array(size);
    
    srand(time(NULL));
    for (size_t index = 0; index < size; index++) {
        
        array[ index ] = rand() % 10;
    }
    
	std::cout << "_______ARRAY__<_INT_>__DEEP__COPY______" << std::endl << std::endl;
	
	std::cout << array << std::endl << std::endl;
	std::cout << "Array adress :" << &array << std::endl << std::endl;
	
    Array<int> tmp = array;
	std::cout << "Array copy adress :" << &tmp << std::endl << std::endl;
    std::cout << tmp << std::endl << std::endl;

	std::cout << "__CHANGED__LAST__ARRAY__INDEX__" << std::endl << std::endl;
    array[ size - 1 ] = 42;
	
    std::cout << tmp << std::endl << std::endl;
    std::cout << array << std::endl << std::endl;
    

    std::cout << "_______ARRAY__EXCEPTIONS__________" << std::endl << std::endl;
	

	std::cout << "TRY NEGATIVE INDEX" << std::endl;
    try
    {
        array[-1] = 0;
    }
    catch( const std::exception& e ) {
		
        std::cout << e.what() << std::endl;
    }
	
	std::cout << std::endl << "TRY TOO HIGH INDEX" << std::endl;

	try
    {
        array[42] = 0;
    }
    catch( const std::exception& e ) {
		
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    
	std::cout << "_______ARRAY__<_CHAR_>__________" << std::endl << std::endl;
	
    Array<char> arrayC(size);
    
    for (size_t index = 0; index < size; index++) {
        
        arrayC[ index ] = 'a' + index ;
    }
    std::cout << arrayC << std::endl << std::endl;

	std::cout << "_______ARRAY__<_STRING_>__________" << std::endl << std::endl;
	
    Array< std::string > arrayStr(size);
    
    std::string str = "string";
    std::string strA[] = {"_a","_b","_c","_d","_e","_f","_g","_h","_i","_j"};
    
    for (size_t index = 0; index < size; index++) {
        
        arrayStr[ index ] = str.append( strA[ index ].c_str() ) ;
    }
    std::cout << arrayStr << std::endl;
    
	return ( EXIT_SUCCESS );
}