/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:38:56 by rpol              #+#    #+#             */
/*   Updated: 2023/02/06 17:30:31 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

int	main(void) {
	
	std::string string =  "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "The memory address of the string variable is: " << &string << std::endl;
	std::cout << "The memory address held by stringPTR is: " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF is: " << &stringREF << std::endl;

	std::cout << "The value of the string variable is: " << string << std::endl;
	std::cout << "The value pointed to by stringPTR is: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF is: " << stringREF << std::endl;
	
	return (EXIT_SUCCESS);
}