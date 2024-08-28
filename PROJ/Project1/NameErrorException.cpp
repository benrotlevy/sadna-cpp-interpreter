#include "NameErrorException.h"

const char* NameErrorException::what() const noexcept
{
    std::string s = "NameError : name '" + _name + "' is not defined";
    char* pointer = new char[s.size() + 1];
    for (int i = 0; i < s.size(); i++)
        pointer[i] = s[i];
    pointer[s.size()] = 0;
    return pointer;
}
