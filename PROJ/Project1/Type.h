#pragma once
#include <string>

class Type
{
public:
	Type() : _isTemp(false) {};
	virtual ~Type() {};
	inline bool getIsTemp() const { return _isTemp; };
	inline void setIsTemp(bool isTemp) { _isTemp = isTemp; };
	virtual bool isPrintable() const = 0;
	virtual std::string toString() const = 0;
	virtual Type* duplicate() const = 0;
private:
	bool _isTemp;
};
