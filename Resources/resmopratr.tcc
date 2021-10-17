#pragma once

/// All the OPERATORS Definations are HERE...

/// @c Author Usama Azad.

usa::string::operator int() const {
    return this->to_int();
}

usa::string::operator float() const {
    return this->to_float();
}

usa::string::operator double() const {
    return this->to_double();
}

usa::string::operator long() const {
    return this->to_long();
}

usa::string::operator long double() const {
    return this->to_longDouble();
}

usa::string::operator char() const {
    return this->to_char();
}

usa::string::operator bool() const {
    return this->to_bool();
}

usa::string::operator std::string() const {
    return this->to_stdString();
}

usa::string::operator const char* () const {
    return this->c_str();
}

#include "resmblfun.tcc"