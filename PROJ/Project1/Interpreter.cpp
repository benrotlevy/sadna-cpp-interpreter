#include "Type.h"
#include "InterpreterException.h"
#include "Parser.h"
#include <iostream>
#include "NameErrorException.h"

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "Benjamin"


int main(int argc,char **argv)
{
	std::cout << WELCOME << YOUR_NAME << std::endl;

	std::string input_string;

	// get new command from user
	std::cout << ">>> ";
	std::getline(std::cin, input_string);
	
	while (input_string != "quit()")
	{
		// parsing command
		try
		{
			Helper::rtrim(input_string);
			Type* type = Parser::parseString(input_string);
			if (type->isPrintable())
				std::cout << type->toString() << "\n";
			if(type->getIsTemp())
				delete type;
		}
		catch (NameErrorException& err)
		{
			const char* what = err.what();
			std::cout << what << "\n";
			delete what;
		}
		catch (std::exception& err)
		{
			std::cout << err.what() << "\n";
		}

		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}
	Parser::clear();
	return 0;
}
