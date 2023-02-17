/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:36:50 by rpol              #+#    #+#             */
/*   Updated: 2023/02/17 16:37:00 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

//canon
Conversion::Conversion( void ) : _input("42"), _inputType(INT) {
	
	return;
}

Conversion::Conversion( const Conversion & to_copy ) :

	_input( to_copy.getInput() ),
	_inputType() {
	
	return;
}

Conversion & Conversion::operator=( const Conversion & toTheRight )  {
	
	if ( this == &toTheRight )
		return ( *this );
	this->_input = toTheRight.getInput();
	return ( *this );
}

Conversion::~Conversion( void ) {
	
	return;
}

Conversion::Conversion( std::string input ) : _input(input) {
	
	this->_whatIsType();
	return;
}




void	Conversion::printTheStuff( void ) const {

	switch (this->getInputType())
	{
	case CHAR :
	
		this->_castChar();
		break;
		
	case INT :
	
		this->_castInt();
		break;
		
	case FLOAT :
	
		this->_castFloat();
		break;
		
	case DOUBLE :
	
		this->_castDouble();
		break;
		
	default:
	
		this->_printOther();
		break;
		
	}
}




std::string	Conversion::getInput( void ) const {

	return ( this->_input );
}

char	Conversion::getInputType( void ) const {
	
	return ( this->_inputType );
}




void	Conversion::_whatIsType( void ) {
	
	if ( this->_isChar() ) {
		
		this->_inputType = CHAR;
	
	} else if ( this->_isInt() ) {
		
		this->_inputType = INT;
		
	} else if ( this->_isFloat() ) {
		
		this->_inputType = FLOAT;
		
	} else if ( this->_isDouble() ) {
		
		this->_inputType = DOUBLE;
		
	} else {
		
		this->_inputType = OTHER;
	}
}




bool	Conversion::_isChar( void ) const {
	
	if (this->getInput().length() == 1) {
		
		return ( !isdigit( this->getInput()[0] ) );
	}
	return ( false );
}

bool	Conversion::_isInt( void ) const {
	
	// Use atoi to attempt to convert the input string to an int
    char* end;
    long int li = strtol(this->getInput().c_str(), &end, 10);
    // Check if the conversion was successful and if there are no remaining characters after the number
    return (*end == '\0' && li >= INT_MIN && li <= INT_MAX);
}

bool	Conversion::_isFloat( void ) const {
	
	// Use atof to attempt to convert the input string to a float
    char* end;
    float f = strtof(this->getInput().c_str(), &end);
    // Check if the conversion was successful, if there is an 'f' suffix, and if there are no remaining characters after the number
    return (*end == 'f' && *(end + 1) == '\0' && !std::isnan(f) && !std::isinf(f));
}

bool	Conversion::_isDouble( void ) const {
	
	// Use atof to attempt to convert the input string to a double
    char* end;
    double d = strtod(this->getInput().c_str(), &end);
    // Check if the conversion was successful, and if there are no remaining characters after the number
    return (*end == '\0' && !std::isnan(d) && !std::isinf(d));
}




void	Conversion::_castChar( void ) const {

	char c = this->getInput()[0];
	
	this->_printChar( c );

	this->_printInt( static_cast<int>( c ) );

	this->_printFloat( static_cast<float>( c ) );

	this->_printDouble( static_cast<double>( c ) );
	
}

void	Conversion::_castInt( void ) const {

	int n = atoi( this->getInput().c_str() );
	
	if ( n >= CHAR_MIN && n <= CHAR_MAX )
		this->_printChar( static_cast<char>( n ) );
	else
		std::cout << "char: impossible" << std::endl;

	this->_printInt( n );

	this->_printFloat( static_cast<float>( n ) );

	this->_printDouble( static_cast<double>( n ) );
	
}

void	Conversion::_castFloat( void ) const {

	float f = static_cast<float>( atof( this->getInput().c_str() ));
	
	if ( static_cast<int>( f )  >= CHAR_MIN &&
			static_cast<int>( f ) <=  CHAR_MAX )
		this->_printChar( static_cast<char>( f ) );
	else
		std::cout << "char: impossible" << std::endl;

	if ( static_cast<long int>( f )  >= INT_MIN &&
			static_cast< long int>( f ) <= INT_MAX )
		
		this->_printInt( static_cast<int>( f ) );
	else
		std::cout << "int: impossible" << std::endl;

	this->_printFloat( f );

	this->_printDouble( static_cast<double>( f ) );

}

void	Conversion::_castDouble( void ) const {

	double d = atof( this->getInput().c_str() );
	
	if ( static_cast<int>( d )  >= CHAR_MIN &&
			static_cast<int>( d ) <=  CHAR_MAX )
		this->_printChar( static_cast<char>( d ) );
	else
		std::cout << "char: impossible" << std::endl;

	if ( static_cast<long int>( d )  >= INT_MIN &&
			static_cast< long int>( d ) <= INT_MAX )
		
		this->_printInt( static_cast<int>( d ) );
	else
		std::cout << "int: impossible" << std::endl;

	if ( d >= FLT_MIN && d <= FLT_MAX )
		
		this->_printFloat( static_cast<float>( d ) );
	else
		std::cout << "float: impossible" << std::endl;

	this->_printDouble( d );
	
}


void	Conversion::_printChar( char const c ) const {
	
	if (std::isprint(c)) {
		
        std::cout << "char: " << c << std::endl;
		
	} else {
		
        std::cout << "char: Non displayable" << std::endl;
	}
}

void	Conversion::_printInt( int const n ) const {

	std::cout << "int: " << n << std::endl;
}

void	Conversion::_printFloat( float const f ) const {
	
	std::cout << std::setiosflags(std::ios::fixed) << "float: " << std::setprecision(1) << f << "f" << std::endl;
}

void	Conversion::_printDouble( double const d ) const {

	std::cout << std::setiosflags(std::ios::fixed) << "double: " << std::setprecision(1) << d << std::endl;
}

void	Conversion::_printOther( void ) const {
	
	std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
	
	this->_nani();

}

void	Conversion::_nani( void ) const {

	std::string input = this->getInput();
	
	if ( input == "nan" || input == "nanf" ) {
		
		std::cout << "float: nanf" << std::endl;
    	std::cout << "double: nan" << std::endl;
		
	} else if ( input == "-inf" || input == "-inff" ) {
		
		std::cout << "float: -inff" << std::endl;
    	std::cout << "double: -inf" << std::endl;
		
	} else if ( input == "+inf" || input == "+inff" ) {
		
		std::cout << "float: +inff" << std::endl;
    	std::cout << "double: +inf" << std::endl;
		
	} else {
		
		std::cout << "float: impossible" << std::endl;
    	std::cout << "double: impossible" << std::endl;
		
	}
		
}
