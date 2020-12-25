#pragma once

/// All the Function Definations are HERE...

/// @c Author Usama Azad.

vector<string> split(const string& str, const char* delimiter)
{
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;
    while ((end = str.find(delimiter, start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}

#if __cplusplus >= 201103L

    string ltrim(const string& str)
    {
        string s(str);
        s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
        return s;
    }

    string rtrim(const string& str)
    {
        string s(str);
        s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
        return s;
    }

    string trim(const string& str)
    {
        return string(ltrim(rtrim(str)));
    }

    void strip(string& s)
    {
        s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
        s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    }

#endif

string reverse(string str)
{
    string copy = (str);
    for (int i = 0, j = (str.size() - 1); i < str.size(); i++, j--)
        str.at(j) = copy.at(i);
    return str;
}

string replace(string str, char prev, char next)
{
    for (int i = 0; i < str.size(); i++)
        if (str.at(i) == prev)
            str.at(i) = next;
    return str;
}

string replace_first(string str, char prev, char next)
{
    for (int i = 0; i < str.size(); i++)
        if (str.at(i) == prev)
        {
            str.at(i) = next;
            break;
        }
    return str;
}

bool is_Upper(string str)
{
    for (int i = 0; i < str.size(); i++)
        if (str.at(i) >= 97 && str.at(i) <= 122)
            return false;
    return true;
}

bool is_Lower(string str)
{
    for (int i = 0; i < str.size(); i++)
        if (str.at(i) >= 65 && str.at(i) <= 90)
            return false;
    return true;
}

string to_UpperCase(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if ((int)str[i] >= 97 && (int)str[i] <= 122)
        {
            str[i] -= 97;
            str[i] += 65;
        }
        str[i] = (char)str[i];
    }
    return str;
}

string to_LowerCase(string str)
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

#include "resmpriv.tcc"