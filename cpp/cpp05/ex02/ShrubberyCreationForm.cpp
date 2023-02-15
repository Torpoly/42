/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:29:04 by rpol              #+#    #+#             */
/*   Updated: 2023/02/15 03:26:38 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//canon
ShrubberyCreationForm::ShrubberyCreationForm( void ) :

	AForm( "ShrubberyCreationForm",
			SHRUBBERY_GRADE_TO_SIGN,
			SHRUBBERY_GRADE_TO_EXECUTE ),
	_target( "default" ) {

	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & to_copy ) :
	
	AForm ( to_copy ),
	_target( to_copy.getTarget() ) {
		
	return;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( const ShrubberyCreationForm & toTheRight ) {

	std::string * targetPTR = ( std::string * )&this->_target;
	std::string * namePTR = ( std::string * )&this->_name;
	unsigned int * gradeToSignPTR = ( unsigned int * )&this->_gradeToSign;
	unsigned int * gradeToExecutePTR = ( unsigned int * )&this->_gradeToExecute;
	
	*targetPTR = toTheRight.getTarget();
	*namePTR = toTheRight.getName();
	this->_isSigned = toTheRight.getIfSigned();
	*gradeToSignPTR = toTheRight.getGradeToSign();
	*gradeToExecutePTR = toTheRight.getGradeToExecute();
	return ( *this );
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) :
	
	AForm( "ShrubberyCreationForm",
			SHRUBBERY_GRADE_TO_SIGN,
			SHRUBBERY_GRADE_TO_EXECUTE ),
	_target( target ) {

	return;
}

void				ShrubberyCreationForm::_executeAction( void ) const {
	
	std::string file = this->getTarget().append("_shrubbery");
	std::ofstream ofs(file.c_str());
	srand(time(NULL));
	if ( ofs.fail() ) {
		
		std::cout << "could not create " << file << "_shrubbery file" << std::endl;
		return;
	} else if ( std::rand() % 2 == 0 ) {
		
		ofs << "            .        +          .      .          ." << std::endl
    		<< "     .            _        .                    ." << std::endl
    		<< "  ,              /;-._,-.____        ,-----.__" << std::endl
    		<< " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl
    		<< "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl
    		<< "                      ,    `./  \\:. `.   )==-\'  ." << std::endl
    		<< "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl
    		<< ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl
    		<< "       .    /:+- - + +- : :- + + -:\'  /(o-) \\)     ." << std::endl
    		<< "  .      ,=':  \\    ` `/` \' , , ,:\' `'--\".--\"---._/`7" << std::endl
    		<< "   `.   (    \\: \\,-._` ` + \'\\, ,\"   _,--._,---\":.__/" << std::endl
    		<< "              \\:  `  X` _| _,\\/\'   .-\'" << std::endl
    		<< ".               \":._:`\\____  /:\'  /      .           ." << std::endl
    		<< "                    \\::.  :\\/:\'  /              +" << std::endl
    		<< "   .                 `.:.  /:\'  }      ." << std::endl
    		<< "           .           ):_(:;   \\           ." << std::endl
    		<< "                      /:. _/ ,  |" << std::endl
    		<< "                   . (|::.     ,`                  ." << std::endl
    		<< "     .                |::.    \\{" << std::endl
    		<< "                      |::.\\  \\ `." << std::endl
    		<< "                      |:::(\\    |" << std::endl
    		<< "              O       |:::/{ }  |                  (o" << std::endl
    		<< "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl
    		<< "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl
    		<< "      ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~" << std::endl;
	} else {
		
		ofs << "                                                        ." << std::endl
        	<< "                                              .         ;  " << std::endl
        	<< "                 .              .              ;%     ;;   " << std::endl
        	<< "                   ,           ,                :;%  %;   " << std::endl
        	<< "                    :         ;                   :;%;'     .,   " << std::endl
        	<< "           ,.        %;     %;            ;        %;'    ,;   " << std::endl
        	<< "             ;       ;%;  %%;        ,     %;    ;%;    ,%'   " << std::endl
        	<< "              %;       %;%;      ,  ;       %;  ;%;   ,%;'   " << std::endl
        	<< "               ;%;      %;        ;%;        % ;%;  ,%;'   " << std::endl
        	<< "                `%;.     ;%;     %;'         `;%%;.%;'   " << std::endl
        	<< "                 `:;%.    ;%%. %@;        %; ;@%;%'   " << std::endl
        	<< "                    `:%;.  :;bd%;          %;@%;'     " << std::endl
        	<< "                      `@%:.  :;%.         ;@@%;'       " << std::endl
        	<< "                        `@%.  `;@%.      ;@@%;         " << std::endl
        	<< "                          `@%%. `@%%    ;@@%;         " << std::endl
        	<< "                            ;@%. :@%%  %@@%;        " << std::endl
        	<< "                              %@bd%%%bd%%:;        " << std::endl
        	<< "                                #@%%%%%:;;      " << std::endl
        	<< "                                %@@%%%::;     " << std::endl
        	<< "                                %@@@%(o);  . '       " << std::endl
        	<< "                                %@@@o%;:(.,'     " << std::endl
        	<< "                            `.. %@@@o%::;       " << std::endl
        	<< "                               `)@@@o%::;       " << std::endl
        	<< "                                %@@(o)::;        " << std::endl
        	<< "                               .%@@@@%::;         " << std::endl
        	<< "                               ;%@@@@%::;.          " << std::endl
        	<< "                              ;%@@@@%%:;;;.     " << std::endl
        	<< "                          ...;%@@@@@%%:;;;;,..     " << std::endl;
		
	}
	ofs.close();
}

std::string		ShrubberyCreationForm::getTarget( void ) const {

	return ( this->_target );
}

std::ostream & operator<<( std::ostream & o, ShrubberyCreationForm const & toTheRight ) {

	o << toTheRight.getName() << ", is a" << ( toTheRight.getIfSigned() ? " signed" : "n unsigned" )
	<< " Form targeting " << toTheRight.getTarget() << " with a grade to sign at " 
	<< toTheRight.getGradeToSign() << ", and grade to execute at " << toTheRight.getGradeToExecute();
	return o;
}