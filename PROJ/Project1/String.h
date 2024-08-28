#pragma once
#include <string>
#include "Sequence.h"

class String : public Sequence
{
public:
	inline String(std::string s) : Sequence(), _val(s) {};
	inline bool isPrintable() const { return true; };
	virtual std::string toString() const;
	virtual Type* duplicate() const;
private:
	std::string _val;
};