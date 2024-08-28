#pragma once
#include "Type.h"
#include <string>

class Integer : public Type
{
public:
	inline Integer(int i) : Type(), _val(i) {};
	inline bool isPrintable() const { return true; };
	virtual std::string toString() const;
	virtual Type* duplicate() const;
private:
	int _val;
};