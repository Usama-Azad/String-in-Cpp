#pragma once

/// All the Function Definations are HERE...

/// @c Author Usama Azad.

bool usa::string::is_upper()
{
    for (int i = 0; i < this->size(); i++)
        if (this->at(i) >= 97 && this->at(i) <= 122)
            return false;
    return true;
}

bool usa::string::is_lower()
{
    for (int i = 0; i < this->size(); i++)
        if (this->at(i) >= 65 && this->at(i) <= 90)
            return false;
    return true;
}

bool usa::string::is_alpha()
{
    if (this->is_contain_space() || this->is_contain() || this->is_None())
        return false;
    for (int i = 0; i < this->size(); i++)
        if (this->at(i) >= '0' && this->at(i) <= '9')
            return false;
    return true;
}

bool usa::string::is_alnum()
{
    if (this->is_contain_space() || this->is_contain() || this->is_None())
        return false;
    return true;
}

bool usa::string::is_numeric()
{
    if (this->is_contain_space() || this->is_contain() || this->is_None())
        return false;
    for (int i = 0; i < this->size(); i++)
        if (this->at(i) >= 'a' && this->at(i) <= 'z' || this->at(i) >= 'A' && this->at(i) <= 'Z')
            return false;
    return true;
}

bool usa::string::is_space()
{
    if (this->is_None())
        return false;
    for (int i = 0; i < this->size(); i++)
        if (this->at(i) != ' ')
            return false;
    return true;
}

bool usa::string::is_contain_space()
{
    if (!this->is_None())
        for (int i = 0; i < this->size(); i++)
            if (this->at(i) == ' ')
                return true;
    return false;
}

bool usa::string::is_contain(const char* type)
{
    for (char c : *this)
        for (char s : std::string(type))
            if (c == s)
                return true;
    return false;
}

bool usa::string::startswith(std::string str, bool match_case)
{
    std::string cmp1 = (match_case) ? (*this) : Lower_Case(*this);
    std::string cmp2 = (match_case) ? str : Lower_Case(str);
    for (int i = 0; i < cmp2.size(); i++)
        if (cmp1[i] != cmp2[i])
            return false;
    return true;
}

bool usa::string::endswith(std::string str, bool match_case)
{
    std::string cmp1 = (match_case) ? (*this) : Lower_Case(*this);
    std::string cmp2 = (match_case) ? str : Lower_Case(str);
    int where = cmp1.size() - cmp2.size(), j = 0;
    for (int i = where; i < cmp1.size(); i++)
        if (cmp1[i] != cmp2[j++])
            return false;
    return true;
}

int usa::string::count(char ch)
{
    int cnt = 0;
    for (int i = 0; i < this->size(); i++)
        if (this->at(i) == ch)
            cnt++;
    return cnt;
}

int usa::string::find_str(std::string str, int pos, bool match_case)
{
    std::string cmp1 = (match_case) ? (*this) : Lower_Case(*this);
    std::string cmp2 = (match_case) ? str : Lower_Case(str);
    return (cmp1.find(cmp2, pos) != std::string::npos) ? cmp1.find(cmp2, pos) : -1;
}

#include "resmcon.tcc"