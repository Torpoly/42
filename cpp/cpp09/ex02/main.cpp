/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 01:37:40 by rpol              #+#    #+#             */
/*   Updated: 2023/03/27 15:38:10 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {

    if (argc == 1) {
        std::cout << "Error: Usage: ./PmergeMe <list of positive interger>" << std::endl;
        return EXIT_FAILURE;
    }
    
    PmergeMe pmm;
    
    try {
		
        pmm.merge_insert_sort_list( argc, argv );
        pmm.merge_insert_sort_deque( argc, argv );
        pmm.print_informations( argc, argv );
    } catch (const std::runtime_error& e) {
		
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}