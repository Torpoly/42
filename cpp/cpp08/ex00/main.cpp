/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:51:37 by rpol              #+#    #+#             */
/*   Updated: 2023/02/20 16:21:33 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main( void ) {
	
    std::vector<int> container;
    container.push_back(1);
    container.push_back(2);
    container.push_back(3);
    container.push_back(4);
    container.push_back(5);

	std::cout << std::endl << "____TEST__FOR__EXISTING__VALUE______" << std::endl << std::endl;

    try {
		
        std::vector<int>::iterator it = easyfind(container, 3);
        std::cout << "Found value " << *it << " in container" << std::endl;
		
    } catch ( const std::runtime_error & e ) {
		
        std::cerr << e.what() << std::endl;
    }

	std::cout << std::endl << "____TEST__FOR__NON__EXISTING__VALUE______" << std::endl << std::endl;

    try {
		
        std::vector<int>::iterator it = easyfind(container, 6);
        std::cout << "Found value " << *it << " in container" << std::endl;
		
    } catch ( const std::runtime_error & e ) {
		
        std::cerr << e.what() << std::endl;
    }

	std::cout << std::endl;

    return ( EXIT_SUCCESS );
}