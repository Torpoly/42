/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:17:36 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 15:04:53 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main( void ) {

{
	
const AAnimal* j = new Dog();
const AAnimal* i = new Cat();

// const AAnimal* k = new AAnimal();
// std::cout << k->getType() << std::endl;
// delete k;

delete j;//should not create a leak
delete i;

std::cout << std::endl;

int n = 10;
AAnimal* animals[n];
	for(int i = 0; i < n; i++){
		if (i % 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
		}
	for(int i = 0; i < n; i++)
		delete animals[i];

std::cout << std::endl;

Dog* dog1 = new Dog();
dog1->setIdea( 0, "I want to be the bestest of good boys" );
const Dog* dog2 = new Dog(*dog1);
dog1->printBrainAdresse();
std::cout << dog1->getIdea( 0 ) << std::endl;
std::cout << dog1->getIdea( 1 ) << std::endl;
dog2->printBrainAdresse();
std::cout << dog2->getIdea( 0 ) << std::endl;
std::cout << dog2->getIdea( 1 ) << std::endl;

std::cout << std::endl;

delete dog1;
delete dog2;

std::cout << std::endl;

}



return ( EXIT_SUCCESS );
}