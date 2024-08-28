#include "Parser.h"
#include <iostream>
#include "Helper.h"
#include "Boolean.h"
#include "Integer.h"
#include "String.h"
#include "SyntaxException.h"
#include "NameErrorException.h"
#include "Void.h"
#include <algorithm>

std::unordered_map<std::string, Type*> Parser::_variables;


Type* Parser::parseString(std::string str)
{
	if (str[0] == ' ' || str[0] == '\t')
		throw(IndentationException());
	Type* type = getVariableValue(str);
	if (type)
		return type;
	type = getType(str);
	if (type == nullptr) {
		if (!makeAssignment(str))
			throw(NameErrorException(str));
	}
	type = new Void();
	type->setIsTemp(true);
	return type;
}

Type* Parser::getType(std::string& str)
{
	Helper::trim(str);
	Type* typeP = nullptr;
	if (Helper::isBoolean(str))
		typeP = new Boolean(str == "True");
	else if(Helper::isInteger(str))
		typeP = new Integer(std::stoi(str));
	else if (Helper::isString(str))
		typeP = new String(str);
	if(typeP)
		typeP->setIsTemp(true);
	return typeP;
}

void Parser::clear()
{
	std::for_each(_variables.begin(), _variables.end(), [](auto p) {delete p.second; });
}

bool Parser::isLegalVarName(std::string str)
{
	if (str.size() == 0)
		return false;
	for (char c : str)
	{
		if (!Helper::isLetter(c) && !Helper::isDigit(c) && !Helper::isUnderscore(c))
			return false;
	}
	return true;
}

//bool assignmentSignError(std::string str)
//{
//	auto assignLoc = str.find('=');
//	if (assignLoc == std::string::npos)
//	return false;
//	if (assignLoc != str.find_last_of('='))
//	return false;
//}

bool Parser::makeAssignment(std::string str)
{
	auto assignLoc = str.find('=');
	if (assignLoc == std::string::npos)
		return false;
	if (assignLoc != str.find_last_of('='))
		return false;
	std::string name = str.substr(0, assignLoc);
	Helper::trim(name);
	if (!isLegalVarName(name))
		throw(SyntaxException());
	std::string value = str.substr(assignLoc + 1);
	Helper::trim(value);
	Type* type = getType(value);
	if (type)
	{
		delete _variables[name];
		_variables[name] = type;
		type->setIsTemp(false);
		return true;
	}
	type = getVariableValue(value);
	if (!type)
	{
		if (!isLegalVarName(value))
		{
			throw(SyntaxException());
		}
		throw(NameErrorException(value));
	}
	delete _variables[name];
	_variables[name] = type->duplicate();
	type->setIsTemp(false);
	return true;
}

Type* Parser::getVariableValue(std::string str)
{
	auto iter = _variables.find(str);
	if (iter == _variables.end())
		return nullptr;
	Type* type = _variables.at(str);
	return type;
}


