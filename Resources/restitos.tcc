#pragma once

/// All the Function Definations are HERE...

/// @c Author Usama Azad.

/// @e convet_to_string.

inline
string __cdecl ItoS(const int &val)
{
    return to_string(val);
}

inline
string __cdecl CtoS(const char &val)
{
    stringstream s;
    s << val;
    return s.str();
}

inline
string __cdecl FtoS(const float &val)
{
    stringstream s;
    s << val;
    return s.str();
}

inline
string __cdecl DtoS(const double &val)
{
    stringstream s;
    s << val;
    return s.str();
}

inline
string __cdecl LtoS(const long &val)
{
    return to_string(val);
}

inline
string __cdecl LDtoS(const long double &val)
{
    stringstream s;
    s << val;
    return s.str();
}

inline
string __cdecl BtoS(const bool &val)
{
    if (val)
        return string("true");
    return string("false");
}

/// @a Convesions_Ends.

#include "restfuncs.tcc"