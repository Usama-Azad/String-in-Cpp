#pragma once

/// All the Function Definations are HERE...

/// @c Author Usama Azad.

std::string usa::string::Lower_Case(std::string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if ((int)str[i] >= 65 && (int)str[i] <= 90)
        {
            str[i] -= 65;
            str[i] += 97;
        }
        str[i] = (char)str[i];
    }
    return str;
}

usa::string& usa::string::replace_ch(char _old, char _new, bool first)
{
    for (int i = 0; i < this->size(); i++)
    {
        if (this->at(i) == _old)
        {
            this->at(i) = _new;
            if (first)
                break;
        }
    }
    return *this;
}

usa::string& usa::string::replace_str(std::string _old, std::string _new, bool first)
{
    int start = 0, end = 0;
    int len = _old.size();
    std::string newstr = "";
    while ((end = this->find(_old, start)) != std::string::npos)
    {
        newstr += (this->substr(start, end - start)) + _new + (this->substr(end + len, this->size()));
        this->assign(newstr);
        newstr = "";
        if (first)
            break;
    }
    return *this;
}
    
#include "resmopratr.tcc"