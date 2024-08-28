#pragma once
#include "Type.h"
#include <string>

class Boolean : public Type
{
public:
	inline Boolean(bool b) : Type(), _val(b) {};
	inline bool isPrintable() const { return true; };
	virtual std::string toString() const;
	virtual Type* duplicate() const;
private:
	bool _val;
};