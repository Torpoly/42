/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:03:01 by rpol              #+#    #+#             */
/*   Updated: 2023/02/21 00:29:10 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main( void )
{
	std::cout << std::endl << "___MUTANTSTACK__TESTS___" << std::endl << std::endl;
	
	MutantStack<int> mstack;
	
	std::cout << "Pushing 5 on top" << std::endl;
	mstack.push(5);
	std::cout << "Pushing 17 on top" << std::endl;
	mstack.push(17);
	
	std::cout << "On top of the stack is :";
	std::cout << mstack.top() << std::endl;

	std::cout << "Removed top element" << std::endl;
	mstack.pop();

	std::cout << "Size of the stack is :";
	std::cout << mstack.size() << std::endl;
	
	std::cout << "Pushing 3 on top" << std::endl;
	mstack.push(3);
	std::cout << "Pushing 5 on top" << std::endl;
	mstack.push(5);
	std::cout << "Pushing 737 on top" << std::endl;
	mstack.push(737);
	std::cout << "Pushing 0 on top" << std::endl;
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	
	std::cout << std::endl << "___PRINT__MUTANTSTACK___" << std::endl << std::endl;
	while (it != ite) {
		
		std::cout << *it << std::endl;
		++it;
	}
	
	MutantStack<int> cmstack(mstack);
	cmstack = mstack;
	
	MutantStack<int>::iterator it1 = cmstack.begin();
	MutantStack<int>::iterator it1e = cmstack.end();
	
	std::cout << std::endl << "___PRINT__MUTANTSTACK__COPY___" << std::endl << std::endl;
	while (it1 != it1e) {
		
		std::cout << *it1 << std::endl;
		++it1;
	}
	
	std::stack<int> s(mstack);
	
	std::cout << std::endl;


	std::cout << std::endl << "___LIST__TESTS___" << std::endl << std::endl;
	std::list<int> mlist;

	std::cout << "Pushing 5 in back" << std::endl;
	mlist.push_back(5);
	std::cout << "Pushing 17 in back" << std::endl;
	mlist.push_back(17);
	
	std::cout << "On back of the list is :";
	std::cout << mlist.back() << std::endl;
	
	std::cout << "Removed back element" << std::endl;
	mlist.pop_back();

	std::cout << "The size of the list is :";
	std::cout << mlist.size() << std::endl;
	
	std::cout << "Pushing 3 in back" << std::endl;
	mlist.push_back(3);
	std::cout << "Pushing 5 in back" << std::endl;
	mlist.push_back(5);
	std::cout << "Pushing 737 in back" << std::endl;
	mlist.push_back(737);
	std::cout << "Pushing 0 in back" << std::endl;
	mlist.push_back(0);
	
	std::list<int>::iterator it2 = mlist.begin();
	std::list<int>::iterator it2e = mlist.end();
	
	++it2;
	--it2;
	
	std::cout << std::endl << "___PRINT__LIST___" << std::endl << std::endl;
	
	while (it2 != it2e)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	
	std::cout << std::endl;
	
	return ( EXIT_SUCCESS );
}