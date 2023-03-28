/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 01:36:58 by rpol              #+#    #+#             */
/*   Updated: 2023/03/27 15:37:17 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


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
	
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token) {

		if (token.find_first_not_of("0123456789+-*/") != std::string::npos) {
			throw std::runtime_error("Invalid character in expression.");
		}
		
		if (token == "+" || token == "-" || token == "*" || token == "/") {

			if (this->_stack.size() < 2) {
				throw std::runtime_error("Invalid RPN expression.");
			}
			
			double b = this->_stack.top(); 
			this->_stack.pop();
			double a = this->_stack.top(); 
			this->_stack.pop();

			if (token == "+") {
				this->_stack.push(a + b);
			} else if (token == "-") {
				this->_stack.push(a - b);
			} else if (token == "*") {
				this->_stack.push(a * b);
			} else if (token == "/") {
				if (b == 0) {
					throw std::runtime_error("Only Chuck Norris can divide by zero.");
				}
				this->_stack.push(a / b);
			}
		} else {
			
			this->_stack.push(atof(token.c_str()));
		}
	}

	if (this->_stack.size() != 1) {
		
		throw std::runtime_error("Invalid RPN expression.");
	}

	return this->_stack.top();
}
