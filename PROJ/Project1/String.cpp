#include "String.h"
#include "Helper.h"

std::string String::toString() const
{ 
    std::string val = _val.substr(1, _val.size() - 2);
    return Helper::hasSingle(val, '\'') ? "\"" + val + "\"" : "'" + val + "'";
}

Type* String::duplicate() const
{
    return new String(_val);
}
