/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:12:29 by rpol              #+#    #+#             */
/*   Updated: 2023/03/27 00:20:22 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <cstdlib>
#include <time.h>
#include <string>
#include <sstream>
#include <list>
#include <deque>
#include <stdexcept>
#include <iostream>
#include <iomanip>

class PmergeMe {
	
	public:

		//////// Orthodox Canonical Form /////////
		PmergeMe( void );
		PmergeMe( const PmergeMe &toCopy );
		PmergeMe &operator=( const PmergeMe &toTheRight );
		~PmergeMe( void );

		/////// METHODS /////////
		void merge_insert_sort_list( int &argc, char **argv );
		void merge_insert_sort_deque( int &argc, char **argv );
		void print_informations( int &argc, char **argv ) const;
		
	private:

		/////// PRIV METHODS /////////
		void 			_merge_insert_sort_deque(std::deque<int> &deq);
		void 			_merge_insert_sort_list(std::list<int> &lst);
		
		std::list<int>	_list;
		double 			_time_list;
		
		std::deque<int> _deque;
		double 			_time_deque;
};

#endif