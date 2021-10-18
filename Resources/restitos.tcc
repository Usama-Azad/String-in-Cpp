#pragma once

/// All the Function Definations are HERE...

/// @c Author Usama Azad.

/// @e convert_to_string.

inline
string ItoS(const int &val) {
    return to_string(val);
}

inline
string CtoS(const char &val) {
    stringstream s;
    s << val;
    return s.str();
}

inline
string FtoS(const float &val) {
    stringstream s;
    s << val;
    return s.str();
}

inline
string DtoS(const double &val) {
    stringstream s;
    s << val;
    return s.str();
}

inline
string LtoS(const long &val) {
    return to_string(val);
}

inline
string LDtoS(const long double &val) {
    stringstream s;
    s << val;
    return s.str();
}

inline
string BtoS(const bool &val) {
    if (val)
        return string("true");
    return string("false");
}

/// @a Convesions_Ends.

#include "restfuncs.tcc"