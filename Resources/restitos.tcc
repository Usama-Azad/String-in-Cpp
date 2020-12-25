#pragma once

/// All the Function Definations are HERE...

/// @c Author Usama Azad.

/// @e convet_to_string.

inline
string __cdecl ItoS(int val)
{
    return to_string(val);
}

inline
string __cdecl CtoS(char val)
{
    stringstream s;
    s << val;
    return s.str();
}

inline
string __cdecl FtoS(float val)
{
    stringstream s;
    s << val;
    return s.str();
}

inline
string __cdecl DtoS(double val)
{
    stringstream s;
    s << val;
    return s.str();
}

inline
string __cdecl LtoS(long val)
{
    return to_string(val);
}

inline
string __cdecl LDtoS(long double val)
{
    stringstream s;
    s << val;
    return s.str();
}

inline
string __cdecl BtoS(bool val)
{
    if (val)
        return string("true");
    return string("false");
}

/// @a Convesions_Ends.

#include "restfuncs.tcc"