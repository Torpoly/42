/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 01:36:58 by rpol              #+#    #+#             */
/*   Updated: 2023/03/25 01:55:47 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <stdexcept>

RPN::RPN( void ) {
	
	return;
}

RPN::RPN(const RPN &toCopy) {
	
	*this = toCopy;
	return;
}


RPN& RPN::operator=(const RPN &toTheRight) {
	
	if (this == &toTheRight) {
		return *this;
	}
	return *this;
}

RPN::~RPN( void ) {
	
	return;
}

double RPN::evaluate( const std::string &expression ) {
	std::stack<double> s;
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token) {

		if (token.find_first_not_of("0123456789+-*/") != std::string::npos) {
			throw std::runtime_error("Invalid character in expression.");
		}
		
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (s.size() < 2) {
				throw std::runtime_error("Invalid RPN expression.");
			}
			double b = s.top(); s.pop();
			double a = s.top(); s.pop();

			if (token == "+") {
				s.push(a + b);
			} else if (token == "-") {
				s.push(a - b);
			} else if (token == "*") {
				s.push(a * b);
			} else if (token == "/") {
				if (b == 0) {
					throw std::runtime_error("Division by zero.");
				}
				s.push(a / b);
			}
		} else {
			s.push(atof(token.c_str()));
		}
	}

	if (s.size() != 1) {
		throw std::runtime_error("Invalid RPN expression.");
	}

	return s.top();
}
