/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:17:36 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 14:47:29 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void ) {

{
	
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();

std::cout << std::endl;

std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;

std::cout << std::endl;

i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

std::cout << std::endl;

delete meta;
delete j;
delete i;

}
std::cout << std::endl;
std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
std::cout << std::endl;
{
	
const WrongAnimal* Wrong_meta = new WrongAnimal();
const WrongAnimal* Wrong_i = new WrongCat();

std::cout << std::endl;

std::cout << Wrong_meta->getType() << " " << std::endl;
std::cout << Wrong_i->getType() << " " << std::endl;

std::cout << std::endl;

Wrong_i->makeSound(); //will output the Wrong animal sound!
Wrong_meta->makeSound();

std::cout << std::endl;

delete Wrong_meta;
delete Wrong_i;

const WrongCat* Wrong_cat = new WrongCat();

std::cout << Wrong_cat->getType() << " " << std::endl;
Wrong_cat->makeSound(); //will output the Wrong cat sound!

std::cout << std::endl;

delete Wrong_cat;

}

return ( EXIT_SUCCESS );
}