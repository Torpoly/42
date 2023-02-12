/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:17:36 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 00:10:15 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main( void ) {
	
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();

std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

delete meta;
delete j;
delete i;

const WrongAnimal* Wrong_meta = new WrongAnimal();
const WrongAnimal* Wrong_j = new WrongDog();
const WrongAnimal* Wrong_i = new WrongCat();

std::cout << Wrong_j->getType() << " " << std::endl;
std::cout << Wrong_i->getType() << " " << std::endl;
Wrong_i->makeSound(); //will output the Wrong animal sound!
Wrong_j->makeSound();
Wrong_meta->makeSound();

delete Wrong_meta;
delete Wrong_j;
delete Wrong_i;

return ( EXIT_SUCCESS );
}