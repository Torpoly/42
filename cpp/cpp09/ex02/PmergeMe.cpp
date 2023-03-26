/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:12:25 by rpol              #+#    #+#             */
/*   Updated: 2023/03/26 23:36:49 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe( void ) {
	
	return;
}

PmergeMe::PmergeMe( const PmergeMe &toCopy ) {

	*this = toCopy;
	return;
}


PmergeMe &PmergeMe::operator=( const PmergeMe &toTheRight ) {
    
	if (this == &toTheRight) {
		return *this;
	}
	return *this;
}

PmergeMe::~PmergeMe() {
}

void PmergeMe::_merge_insert_sort_list( std::list<int> &lst ) {
	
    if (lst.size() <= 1) {
        return;
    }

    std::list<int>::iterator middle = lst.begin();
    for (size_t i = 0; i < lst.size() / 2; ++i) {
        ++middle;
    }

    std::list<int> left(lst.begin(), middle);
    std::list<int> right(middle, lst.end());

    this->_merge_insert_sort_list(left);
    this->_merge_insert_sort_list(right);

    lst.clear();
    std::list<int>::iterator left_it = left.begin();
    std::list<int>::iterator right_it = right.begin();

    while (left_it != left.end() && right_it != right.end()) {
        if (*left_it <= *right_it) {
            lst.push_back(*left_it);
            ++left_it;
        } else {
            lst.push_back(*right_it);
            ++right_it;
        }
    }

    while (left_it != left.end()) {
        lst.push_back(*left_it);
        ++left_it;
    }

    while (right_it != right.end()) {
        lst.push_back(*right_it);
        ++right_it;
    }
}

void PmergeMe::_merge_insert_sort_deque( std::deque<int> &deq ) {
    
	if (deq.size() <= 1) {
        return;
    }

    std::deque<int> left(deq.begin(), deq.begin() + deq.size() / 2);
    std::deque<int> right(deq.begin() + deq.size() / 2, deq.end());

    this->_merge_insert_sort_deque(left);
    this->_merge_insert_sort_deque(right);

    deq.clear();
    std::deque<int>::iterator left_it = left.begin();
    std::deque<int>::iterator right_it = right.begin();

    while (left_it != left.end() && right_it != right.end()) {
        if (*left_it <= *right_it) {
            deq.push_back(*left_it);
            ++left_it;
        } else {
            deq.push_back(*right_it);
            ++right_it;
        }
    }

    while (left_it != left.end()) {
        deq.push_back(*left_it);
        ++left_it;
    }

    while (right_it != right.end()) {
        deq.push_back(*right_it);
        ++right_it;
    }
}

void PmergeMe::merge_insert_sort_list( int &argc, char **argv ) {
	
	timespec start_list, end_list;
	// start time
	clock_gettime(CLOCK_MONOTONIC, &start_list);
	//data managment
	for (int i = 1; i < argc; ++i) {
        int value = std::atoi(argv[i]);
        if (value <= 0) {
            throw std::runtime_error("Invalid input not a positive integer.");
            return;
        }
        this->_list.push_back(value);
    }
    //sort
	this->_merge_insert_sort_list(this->_list);
	
    //end time
    clock_gettime(CLOCK_MONOTONIC, &end_list);
	//get microseconds
     this->_time_list = static_cast<double>((end_list.tv_sec - start_list.tv_sec) * 1000000000 +
                                             (end_list.tv_nsec - start_list.tv_nsec)) / 1000.0;
}

void PmergeMe::merge_insert_sort_deque( int &argc, char **argv ) {
	
	timespec start_deque, end_deque;
	// start time
	clock_gettime(CLOCK_MONOTONIC, &start_deque);
	//data managment
	for (int i = 1; i < argc; ++i) {
        int value = std::atoi(argv[i]);
        if (value <= 0) {
            throw std::runtime_error("Invalid input not a positive integer.");
            return;
        }
        this->_deque.push_back(value);
    }
    //sort
	this->_merge_insert_sort_deque(this->_deque);
	//end time
    clock_gettime(CLOCK_MONOTONIC, &end_deque);
	//get microseconds
     this->_time_deque = static_cast<double>((end_deque.tv_sec - start_deque.tv_sec) * 1000000000 +
                                             (end_deque.tv_nsec - start_deque.tv_nsec)) / 1000.0;
}

void PmergeMe::print_informations( int &argc, char **argv ) const {
	
	std::cout << "Before: ";
    for (int i = 1; i < argc; ++i) {
        std::cout << " " << argv[i];
    }
    std::cout << std::endl;
	
    std::stringstream result;
    for (std::list<int>::const_iterator it = _list.begin(); it != _list.end(); ++it) {
        result << *it << " ";
    }
    std::cout << "After:   " << result.str() << std::endl;
	std::cout << "Time to process a range of  " << this->_list.size() << " elements with std::list : " << std::fixed << std::setprecision(5) << this->_time_list << " us" << std::endl;
    std::cout << "Time to process a range of  " << this->_deque.size() << " elements with std::deque : " << std::fixed << std::setprecision(5) << this->_time_deque << " us" << std::endl;
}
