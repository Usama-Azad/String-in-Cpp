#pragma once

/// All the Function Definations are HERE...

/// @c Author Usama Azad.

/// @e convert_from_string.

inline
int StoI(const string &str) {
    return stoi(str);
}

inline
char StoC(const string &str) {
    return char(str[0]);
}

inline
float StoF(const string &str) {
    return stof(str);
}

inline
double StoD(const string &str) {
    return stod(str);
}

inline
long StoL(const string &str) {
    return stol(str);
}

inline
long double StoLD(const string &str) {
    return stold(str);
}

// Prototype or Forward declaration
string to_LowerCase(string);

inline
bool StoB(const string &str) {
    return (to_LowerCase(str) == "true" || str == "1");
}

/// @a Convesions_Ends.

#include "restitos.tcc"