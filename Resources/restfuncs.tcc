#pragma once

/// All the Function Definations are HERE...

/// @c Author Usama Azad.

vector<string> split(const string& str, const char &delimiter)
{
    vector<std::string> tokens;
    size_t start = 0, end = 0;

    while ((end = str.find(delimiter, start)) != std::string::npos)
    {
#if __cplusplus >= 201102L
        tokens.emplace_back(_trim(str.substr(start, end - start)));
#else
        tokens.emplace_back((str.substr(start, end - start)));
#endif
        start = end + 1;
    }

#if __cplusplus >= 201102L
    tokens.emplace_back(_trim(str.substr(start)));
#else
    tokens.emplace_back((str.substr(start)));
#endif
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

    string _trim(const string& str)
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
    int len = str.size();
    for (int i = 0; i < len / 2; i++)
        str.at(i) = exchangeX(str.at(len - 1 - i), str.at(i));
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

bool is_Upper(const string &str)
{
    for (const char& ch : str)
        if (ch & 0x20)
            return false;
    return true;
}

bool is_Lower(const string &str)
{
    for (const char& ch : str)
        if (!(ch & 0x20))
            return false;
    return true;
}

string to_UpperCase(string str)
{
    for (char & ch : str)
        if (ch >= 0x61 && ch <= 0x7A)
            ch -= 0x20;
    return str;
}

string to_LowerCase(string str)
{
    for (char& ch : str)
        if (ch >= 0x41 && ch <= 0x5A)
            ch += 0x20;
    return str;
}

#include "resmpriv.tcc"