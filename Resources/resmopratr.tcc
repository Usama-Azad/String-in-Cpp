#pragma once

/// All the OPERATORS Definations are HERE...

/// @c Author Usama Azad.

usa::string::operator int()
{
    return this->to_int();
}

usa::string::operator float()
{
    return this->to_float();
}

usa::string::operator double()
{
    return this->to_double();
}

usa::string::operator long()
{
    return this->to_long();
}

usa::string::operator long double()
{
    return this->to_longdouble();
}

usa::string::operator char()
{
    return this->to_char();
}

usa::string::operator bool()
{
    return this->to_bool();
}

usa::string::operator std::string()
{
    return this->to_std_string();
}

usa::string::operator const char* ()
{
    return this->c_str();
}

#include "resmblfun.tcc"