#pragma once

/// All the Function Definations are HERE...

/// @c Author Usama Azad.

bool usa::string::is_upper() const
{
    for (const char &ch : *this)
        if(ch & 0x20)
            return false;
    return true;
}

bool usa::string::is_lower() const
{
    for (const char& ch : *this)
        if (!(ch & 0x20))
            return false;
    return true;
}

bool usa::string::is_alpha() const
{
    if (this->is_contain_space() || this->is_contain_any(special_chars) || this->is_None())
        return false;
    for (int i = 0; i < this->size(); i++)
        if (this->at(i) >= '0' && this->at(i) <= '9')
            return false;
    return true;            
}

bool usa::string::is_alnum() const
{
    return !(this->is_contain_space() || this->is_contain_any(special_chars) || this->is_None());
}

bool usa::string::is_numeric() const
{
    if (this->is_contain_space() || this->is_contain_any(special_chars) || this->is_None())
        return false;
    for (int i = 0; i < this->size(); i++)
        if (this->at(i) >= 'a' && this->at(i) <= 'z' || this->at(i) >= 'A' && this->at(i) <= 'Z')
            return false;
    return true;
}

bool usa::string::is_space() const
{
    if (this->is_None())
        return false;
    for (int i = 0; i < this->size(); i++)
        if (this->at(i) != 32)
            return false;
    return true;
}

bool usa::string::is_contain_space() const
{
    if (!this->is_None())
        for (int i = 0; i < this->size(); i++)
            if (this->at(i) == 32)
                return true;
    return false;
}

bool usa::string::is_contain_any(const char *str) const
{
    for (const char &s : std::string(str))
        for (const char &c : *this)
            if (c == s)
                return true;
    return false;
}

bool usa::string::startswith(const std::string& str, bool match_case)
{
    std::string cmp1 = (match_case) ? (*this) : Lower_Case(*this);
    std::string cmp2 = (match_case) ? str : Lower_Case(str);
    for (int i = 0; i < cmp2.size(); i++)
        if (cmp1[i] != cmp2[i])
            return false;
    return true;
}

bool usa::string::endswith(const std::string& str, bool match_case)
{
    std::string cmp1 = (match_case) ? (*this) : Lower_Case(*this);
    std::string cmp2 = (match_case) ? str : Lower_Case(str);
    int where = cmp1.size() - cmp2.size(), j = 0;
    for (int i = where; i < cmp1.size(); i++)
        if (cmp1[i] != cmp2[j++])
            return false;
    return true;
}

int usa::string::count(const char &ch) const
{
    int cnt = 0;
    for (const char &c : *this)
        if (c == ch)
            cnt++;
    return cnt;
}

int usa::string::countWord(string word, bool match_case) const
{
    string match = *this;
    if (!match_case){
        word.toLowerCase();
        match.toLowerCase();
    }
    int cnt = 0;
    for (const std::string &w : match.split(32))
        if (w == word)
            cnt++;
    return cnt;
}

int usa::string::find_str(const std::string &str, int pos, bool match_case)
{
    std::string cmp1 = (match_case) ? (*this) : Lower_Case(*this);
    std::string cmp2 = (match_case) ? str : Lower_Case(str);
    return (cmp1.find(cmp2, pos) != std::string::npos) ? cmp1.find(cmp2, pos) : -1;
}

#include "resmcon.tcc"