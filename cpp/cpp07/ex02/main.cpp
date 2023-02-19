/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:47:59 by rpol              #+#    #+#             */
/*   Updated: 2023/02/19 11:41:54 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>
#include <ctime>



int main( void ) {

    size_t size = 10;
    
    Array<int> array(size);
    
    srand(time(NULL));
    for (size_t index = 0; index < size; index++) {
        
        array[ index ] = rand() % 10;
    }
    

    {
        Array<int> tmp = array;
        std::cout << tmp << std::endl << std::endl;
        std::cout << array << std::endl << std::endl;
        array[ size - 1 ] = 42;
        std::cout << tmp << std::endl << std::endl;
        std::cout << array << std::endl << std::endl;
    }

    
    try
    {
        array[-1] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
	
    try
    {
        array[size] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

	try
    {
        array[42] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    
    Array<char> arrayC(size);
    
    for (size_t index = 0; index < size; index++) {
        
        arrayC[ index ] = 'a' + index ;
    }
    std::cout << arrayC << std::endl;

    Array< std::string > arrayStr(size);
    
    std::string str = "string";
    std::string strA[] = {"_a","_b","_c","_d","_e","_f","_g","_h","_i","_j"};
    
    for (size_t index = 0; index < size; index++) {
        
        arrayStr[ index ] = str.append( strA[ index ].c_str() ) ;
    }
    std::cout << arrayStr << std::endl;
    
	return ( EXIT_SUCCESS );
}