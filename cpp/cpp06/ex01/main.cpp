/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:21:09 by rpol              #+#    #+#             */
/*   Updated: 2023/02/17 11:08:40 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"


uintptr_t	serialize( Data* ptr ) {
	
	return ( reinterpret_cast<uintptr_t>( ptr) );
}

Data*	deserialize( uintptr_t raw ) {
	
	return ( reinterpret_cast<Data*>( raw ) );
}

int	main( void ) {

	Data *ptr = new Data;
	ptr->data = "*some_data*";

	std::cout << "Data adresss is : " << ptr << std::endl;
	std::cout << "Data memory is : " << ptr->data << std::endl << std::endl;

	uintptr_t raw = serialize( ptr );
	std::cout << "Raw adresss is : " << raw << std::endl << std::endl;

	Data *ptrDeserialized = deserialize( raw );
	std::cout << "Data adresss is : " <<  ptrDeserialized << std::endl;
	std::cout << "Data memory is : " << ptrDeserialized->data << std::endl << std::endl;
	
	delete ptrDeserialized;
	
	return ( EXIT_SUCCESS );
}