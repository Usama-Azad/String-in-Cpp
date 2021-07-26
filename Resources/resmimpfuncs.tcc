#pragma once

/// All the Function Definations are HERE...

/// @c Author Usama Azad.

usa::string& usa::string::replace(const char &_old, const char &_new)
{
    return replace_ch(_old, _new);
}

usa::string& usa::string::replace_first(const char &_old, const char &_new)
{
    return replace_ch(_old, _new, true);
}

usa::string& usa::string::replace(const std::string &_old, const std::string &_new)
{
    return replace_str(_old, _new);
}

usa::string& usa::string::replace_first(const std::string &_old, const std::string &_new)
{
    return replace_str(_old, _new, true);
}

usa::string& usa::string::swapcase()
{
    for (char& ch : *this) {
        if (ch >= 0x41 && ch <= 0x5A)
            ch += 0x20;
        else if (ch >= 0x61 && ch <= 0x7A)
            ch -= 0x20;
    }
    return *this;
}

usa::string& usa::string::title()
{
    this->toLowerCase();

    if (this->at(0) >= 0x61 && this->at(0) <= 0x7A)
        this->at(0) -= 0x20;

    if (!this->is_contain_space())
        if (!this->is_contain_any(special_chars))
            return *this;

    for (const char &x : special_chars)
        for (int i = 0; i < this->size(); i++)
            if ((x == this->at(i) || this->at(i) == ' ') && i != this->size() - 1)
                if (this->at(i + 1) >= 0x61 && this->at(i + 1) <= 0x7A)
                    this->at(i + 1) -= 0x20;

    return *this;
}

usa::string& usa::string::capitalize()
{
    this->toLowerCase();

    if (this->at(0) >= 0x61 && this->at(0) <= 0x7A)
        this->at(0) -= 0x20;

    if (!this->is_contain_any(special_chars))
        return *this;

    for (int i = 0; i < this->size(); i++)
        if (this->at(i) == '.' && i != this->size() - 1)
            if (this->at(i + 1) >= 0x61 && this->at(i + 1) <= 0x7A)
                this->at(i + 1) -= 0x20;

    return *this;
}

usa::string& usa::string::slice(int _start, int _end, int _step)
{
    if (_step < -1)
    {
        int temp = _start; _start = _end; _end = temp;
        _start++;
        _end++;
    }

    if (_start < 0)
        _start = (int(this->size()) + _start);
    if (_end == 0 || _end > int(this->size()))
        _end = (int(this->size()) - _start);
    else if (_end < 0)
        _end = (int(this->size()) + _end - _start);
    else
        _end = (_end - _start);

    this->assign(this->substr(_start, _end));
    *this = (_step < 0) ? this->reverse() : *this;

    if (_step != 0 && abs(_step) != 1)
    {
        std::string temp = "";

        int i = 0;
        while ((i * abs(_step)) < int(this->size()))
            temp += this->at(i++ * abs(_step));

        this->assign(temp);
    }

    return *this;
}

usa::string& usa::string::format(const std::vector<usa::string>& arr)
{
    for (auto i : arr)
        this->replace_first("{}", i);
    return *this;
}

usa::string& usa::string::join(const string& obj, const string &delimiter)
{
    (*this) += (delimiter + obj);
    return *this;
}

usa::string& usa::string::join(const std::vector<char> &arr, const string &delimiter, bool swd)
{
    for (const char &x : arr)
        *this += swd ? delimiter + x : x + delimiter;
    return *this;
}

usa::string& usa::string::join(const std::vector<string> &arr, const string &delimiter, bool swd)
{
    for (const string& x : arr)
        *this += swd ? delimiter + x : x + delimiter;
    return *this;
}

usa::string& usa::string::join(const std::vector<std::string> &arr, const string &delimiter, bool swd)
{
    for (const std::string &x : arr)
        *this += swd ? delimiter + x : x + delimiter;
    return *this;
}

usa::string& usa::string::join(const std::initializer_list<string> &arr, const string &delimiter, bool swd)
{
    for (const string &x : arr)
        *this += swd ? delimiter + x : x + delimiter;
    return *this;
}

usa::string& usa::string::reverse()
{
    int len = this->size();
    for (int i = 0; i < len / 2; i++)
        this->at(i) = std::exchange(this->at(len - 1 - i), this->at(i));
    return *this;
}

vector<std::string> usa::string::split(const char &delimiter)
{
    if (count(delimiter) < 1) return {};
    
    vector<std::string> tokens;
    size_t start = 0, end = 0;
    
    while ((end = this->find(delimiter, start)) != std::string::npos)
    {
        tokens.emplace_back(trim_(this->substr(start, end - start)));
        start = end + 1;
    }

    tokens.emplace_back(trim_(this->substr(start)));
    return tokens;
}

vector<std::string> usa::string::splitlines()
{
    return split('\n');
}

#if __cplusplus >= 201103L

    usa::string& usa::string::ltrim()
    {
        string& s = (*this);
        s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
        return s;
    }

    usa::string& usa::string::rtrim()
    {
        string& s = (*this);
        s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
        return s;
    }

    usa::string& usa::string::trim()
    {
        usa::string& s = (*this);
        s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
        s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
        return s;
    }

    void usa::string::strip()
    {
        usa::string& s = (*this);
        s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
        s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    }

#endif

usa::string& usa::string::zfill(int width, char fillChar, bool fillFromStart)
{
    if (this->size() < width)
    {
        int len = width - this->size();
        std::string _str = "";
        for (int i = 0; i < len; i++)
            _str += fillChar;
        *this = (fillFromStart) ? _str + *this : *this + _str;
    }
    return *this;
}

usa::string& usa::string::fill(int _start, int _end, char fillChar)
{
    _end = (_end <= 0 || _end > this->size()) ? this->size() : _end;
    _start = (_start < 0 || _start >= _end) ? 0 : _start;
    for (int i = _start; i < _end; i++)
        this->at(i) = fillChar;
    return *this;
}

usa::string& usa::string::toUpperCase()
{
    for (char& ch : *this)
        if (ch >= 0x61 && ch <= 0x7A)
            ch -= 0x20;
    return *this;
}

usa::string& usa::string::toLowerCase()
{
    for (char& ch : *this)
        if (ch >= 0x41 && ch <= 0x5A)
            ch += 0x20;
    return *this;
}

/// @c Done :):):) .....