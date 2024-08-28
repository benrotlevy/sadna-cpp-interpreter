#include "Boolean.h"

std::string Boolean::toString() const
{
    return _val ? std::string("True") : std::string("False");
}

Type* Boolean::duplicate() const
{
    return new Boolean(_val);
}
