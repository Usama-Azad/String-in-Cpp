#pragma once

/// All the Function Definations are HERE...

/// @c Author Usama Azad.

int usa::string::to_int() const {
    try { return StoI(*this); }
    catch (...) { return 0; }
}

char usa::string::to_char() const {
    try { return StoC(*this); }
    catch (...) { return '\000'; }
}

float usa::string::to_float() const {
    try { return StoF(*this); }
    catch (...) { return 0.f; }
}

double usa::string::to_double() const {
    try { return StoD(*this); }
    catch (...) { return 0.0; }
}

long usa::string::to_long() const {
    try { return StoL(*this); }
    catch (...) { return 0l; }
}

bool usa::string::to_bool() const {
    try { return StoB(*this); }
    catch (...) { return false; }
}

long double usa::string::to_longDouble() const {
    try { return StoLD(*this); }
    catch (...) { return 0.0L; }
}

std::string usa::string::to_stdString() const {
    try { return std::string(*this); }
    catch (...) { return ""; }
}

#include "resmimpfuncs.tcc"