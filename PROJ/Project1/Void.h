#pragma once
#include "Type.h"
#include <string>

class Void : public Type
{
public:
	inline Void() : Type() {};
	inline bool isPrintable() const { return false; };
	virtual std::string toString() const;
	virtual Type* duplicate() const { return new Void(); };
private:
	//bool _val;
};