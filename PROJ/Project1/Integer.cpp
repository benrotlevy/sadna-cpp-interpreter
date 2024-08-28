#include "Integer.h"

std::string Integer::toString() const
{
    return std::to_string(_val);
}

Type* Integer::duplicate() const
{
    return new Integer(_val);
}
