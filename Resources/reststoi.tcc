#pragma once

/// All the Function Definations are HERE...

/// @c Author Usama Azad.

/// @e convert_from_string.

inline
int __cdecl StoI(const string &str) {
    return stoi(str);
}

inline
char __cdecl StoC(const string &str) {
    return char(str[0]);
}

inline
float __cdecl StoF(const string &str) {
    return stof(str);
}

inline
double __cdecl StoD(const string &str) {
    return stod(str);
}

inline
long __cdecl StoL(const string &str) {
    return stol(str);
}

inline
long double __cdecl StoLD(const string &str) {
    return stold(str);
}

// Prototype or Forward declaration
string to_LowerCase(string);

inline
bool __cdecl StoB(const string &str) {
    return (to_LowerCase(str) == "true" || str == "1");
}

/// @a Convesions_Ends.

#include "restitos.tcc"