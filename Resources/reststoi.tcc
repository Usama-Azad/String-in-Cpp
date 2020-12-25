#pragma once

/// All the Function Definations are HERE...

/// @c Author Usama Azad.

/// @e convet_from_string.

inline
int __cdecl StoI(string str)
{
    return stoi(str);
}

inline
char __cdecl StoC(string str)
{
    return char(str[0]);
}

inline
float __cdecl StoF(string str)
{
    return stof(str);
}

inline
double __cdecl StoD(string str)
{
    return stod(str);
}

inline
long __cdecl StoL(string str)
{
    return stol(str);
}

inline
long double __cdecl StoLD(string str)
{
    return stold(str);
}

// Prototype or Forward declaration
string to_LowerCase(string);

inline
bool __cdecl StoB(string str)
{
    if (to_LowerCase(str) == "true" || str == "1")
        return true;
    return false;
}

/// @a Convesions_Ends.

#include "restitos.tcc"