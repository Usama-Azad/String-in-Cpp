#pragma once

/// All the Function Definations are HERE...

/// @c Author Usama Azad.

int usa::string::to_int()
{
    try { return StoI(*this); }
    catch (...) { return 0; }
}

char usa::string::to_char()
{
    try { return StoC(*this); }
    catch (...) { return '\000'; }
}

float usa::string::to_float()
{
    try { return StoF(*this); }
    catch (...) { return 0.f; }
}

double usa::string::to_double()
{
    try { return StoD(*this); }
    catch (...) { return 0.0; }
}

long usa::string::to_long()
{
    try { return StoL(*this); }
    catch (...) { return 0l; }
}

bool usa::string::to_bool()
{
    try { return StoB(*this); }
    catch (...) { return false; }
}

long double usa::string::to_longdouble()
{
    try { return StoLD(*this); }
    catch (...) { return 0.0L; }
}

std::string usa::string::to_std_string()
{
    try { return std::string(*this); }
    catch (...) { return ""; }
}

#include "resmimpfuncs.tcc"