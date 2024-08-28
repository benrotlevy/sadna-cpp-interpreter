#pragma once
#include <exception>


class InterpreterException : public std::exception
{
public:
	virtual ~InterpreterException() {};
};
