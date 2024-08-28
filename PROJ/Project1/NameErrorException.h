#pragma once
#include "InterpreterException.h"
#include <string>

class NameErrorException : public InterpreterException
{
public:
	const char* what() const noexcept;
	inline NameErrorException(std::string name) : InterpreterException(), _name(name) {};
	~NameErrorException() { };
private:
	std::string _name;
	//char* _str;
};