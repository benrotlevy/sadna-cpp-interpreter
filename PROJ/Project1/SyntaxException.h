#pragma once
#include "InterpreterException.h"
#include <string>

class SyntaxException : public InterpreterException
{
public:
	~SyntaxException() {};
	virtual const char* what() const noexcept;
};