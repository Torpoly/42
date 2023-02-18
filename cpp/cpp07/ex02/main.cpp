/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:47:59 by rpol              #+#    #+#             */
/*   Updated: 2023/02/18 20:02:45 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>
#include <ctime>

#define SIZE 10

int main( void ) {

	Array<int> empty(0);
    Array<int> numbers(SIZE);
    int* tab = new int[SIZE];
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++)
    {
        const int value = rand();
        numbers[i] = value;
        tab[i] = value;
    }
    
    {
        Array<int> tmp = numbers;
    }

    for (int i = 0; i < SIZE; i++)
    {
        std::cout	<< "Array[" << i << "] is " << numbers[i]
					<< ", Tab[" << i << "] is " << tab[i] << std::endl;
    }
	
    try
    {
        numbers[-1] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
	
    try
    {
        numbers[SIZE] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

	try
    {
        numbers[42] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    delete [] tab;
	return ( EXIT_SUCCESS );
}