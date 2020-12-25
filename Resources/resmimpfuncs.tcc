#pragma once

/// All the Function Definations are HERE...

/// @c Author Usama Azad.

usa::string& usa::string::replace(char _old, char _new)
{
    return replace_ch(_old, _new);
}

usa::string& usa::string::replace_first(char _old, char _new)
{
    return replace_ch(_old, _new, true);
}

usa::string& usa::string::replace(std::string _old, std::string _new)
{
    return replace_str(_old, _new);
}

usa::string& usa::string::replace_first(std::string _old, std::string _new)
{
    return replace_str(_old, _new, true);
}

usa::string& usa::string::swapcase()
{
    usa::string& name = (*this);
    for (int i = 0; i < name.size(); i++)
    {
        if ((int)name[i] >= 65 && (int)name[i] <= 90)
        {
            name[i] -= 65;
            name[i] += 97;
        }
        else if ((int)name[i] >= 97 && (int)name[i] <= 122)
        {
            name[i] -= 97;
            name[i] += 65;
        }
        name[i] = (char)name[i];
    }
    return name;
}

usa::string& usa::string::title()
{
    this->toLowerCase();
    if ((int)this->at(0) >= 97 && (int)this->at(0) <= 122)
    {
        this->at(0) -= 97;
        this->at(0) += 65;
    }

    if (!this->is_contain_space())
        if (!this->is_contain())
            return *this;

    for (auto x : special_chars)
        for (int i = 0; i < this->size(); i++)
            if (x == this->at(i) || this->at(i) == ' ')
                if ((int)this->at(i + 1) >= 97 && (int)this->at(i + 1) <= 122)
                {
                    this->at(i + 1) -= 97;
                    this->at(i + 1) += 65;
                }

    return *this;
}

usa::string& usa::string::capitalize()
{
    this->toLowerCase();
    if ((int)this->at(0) >= 97 && (int)this->at(0) <= 122)
    {
        this->at(0) -= 97;
        this->at(0) += 65;
    }

    if (!this->is_contain())
        return *this;

    for (int i = 0; i < this->size(); i++)
        if (this->at(i) == '.' && i != this->size() - 1)
            if ((int)this->at(i + 1) >= 97 && (int)this->at(i + 1) <= 122)
            {
                this->at(i + 1) -= 97;
                this->at(i + 1) += 65;
            }

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

usa::string& usa::string::join(const string& obj, string delimiter)
{
    (*this) += delimiter += obj;
    return *this;
}

usa::string& usa::string::join(std::vector<char> arr, string delimiter, bool swd)
{
    for (int i = 0; i < arr.size(); i++)
        if (swd)
            (*this) += (delimiter + arr[i]);
        else
            (*this) += (arr[i] + delimiter);
    return *this;
}

usa::string& usa::string::join(std::vector<string> arr, string delimiter, bool swd)
{
    for (int i = 0; i < arr.size(); i++)
        if (swd)
            (*this) += delimiter + arr[i];
        else
            (*this) += arr[i] + delimiter;
    return *this;
}

usa::string& usa::string::join(std::vector<std::string> arr, string delimiter, bool swd)
{
    for (int i = 0; i < arr.size(); i++)
        if (swd)
            (*this) += delimiter + arr[i];
        else
            (*this) += arr[i] + delimiter;
    return *this;
}

usa::string& usa::string::join(std::initializer_list<string> arr, string delimiter, bool swd)
{
    for (auto x : arr)
        if (swd)
            (*this) += delimiter + x;
        else
            (*this) += x + delimiter;
    return *this;
}

usa::string& usa::string::reverse()
{
    string copy = (*this);
    for (int i = 0, j = (this->size() - 1); i < this->size(); i++, j--)
        this->at(j) = copy.at(i);
    return *this;
}

vector<std::string> usa::string::split(const char* delimiter)
{
    vector<std::string> tokens;
    std::string::size_type start = 0;
    std::string::size_type end = 0;
    while ((end = this->find(delimiter, start)) != std::string::npos)
    {
        tokens.push_back(this->substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(this->substr(start));
    return tokens;
}

vector<std::string> usa::string::splitlines()
{
    return split("\n");
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
    usa::string& name = (*this);
    for (int i = 0; i < name.size(); i++)
    {
        if ((int)name[i] >= 97 && (int)name[i] <= 122)
        {
            name[i] -= 97;
            name[i] += 65;
        }
        name[i] = (char)name[i];
    }
    return name;
}

usa::string& usa::string::toLowerCase()
{
    usa::string& name = (*this);
    for (int i = 0; i < name.size(); i++)
    {
        if ((int)name[i] >= 65 && (int)name[i] <= 90)
        {
            name[i] -= 65;
            name[i] += 97;
        }
        name[i] = (char)name[i];
    }
    return name;
}

/// @c Done :):):) .....