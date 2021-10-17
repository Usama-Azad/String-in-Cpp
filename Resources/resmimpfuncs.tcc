#pragma once

/// All the Function Definations are HERE...

/// @c Author Usama Azad.

usa::string usa::string::replace(const std::string &_old, const std::string &_new) const {
    usa::string res = *this;
    if (_old.size() == 1 && _new.size() == 1)
        return res.replace_ch(_old[0], _new[0]);
    return res.replace_str(_old, _new);
}

usa::string usa::string::replaceFirst(const std::string &_old, const std::string &_new) const {
    usa::string res = *this;
    if (_old.size() == 1 && _new.size() == 1)
        return res.replace_ch(_old[0], _new[0], true);
    return res.replace_str(_old, _new, true);
}

usa::string& usa::string::replace_(const std::string &_old, const std::string &_new) {
    if (_old.size() == 1 && _new.size() == 1)
        return replace_ch(_old[0], _new[0]);
    return replace_str(_old, _new);
}

usa::string& usa::string::replaceFirst_(const std::string &_old, const std::string &_new) {
    if (_old.size() == 1 && _new.size() == 1)
        return replace_ch(_old[0], _new[0], true);
    return replace_str(_old, _new, true);
}


usa::string usa::string::swapcase() const {
    usa::string res = *this;
    for (char& ch : res) {
        if (ch >= 0x41 && ch <= 0x5A)
            ch += 0x20;
        else if (ch >= 0x61 && ch <= 0x7A)
            ch -= 0x20;
    }
    return res;
}

usa::string& usa::string::swapcase_() {
    for (char& ch : *this) {
        if (ch >= 0x41 && ch <= 0x5A)
            ch += 0x20;
        else if (ch >= 0x61 && ch <= 0x7A)
            ch -= 0x20;
    }
    return *this;
}

usa::string usa::string::title() const {
    usa::string res = *this;
    res.toLowerCase_();

    if (res.at(0) >= 0x61 && res.at(0) <= 0x7A)
        res.at(0) -= 0x20;

    if (!res.is_containSpace())
        if (!res.is_containAny(punctuation))
            return res;

    for (const char &x : punctuation)
        for (int i = 0; i < res.size(); i++)
            if ((x == res.at(i) || res.at(i) == ' ') && i != res.size() - 1)
                if (res.at(i + 1) >= 0x61 && res.at(i + 1) <= 0x7A)
                    res.at(i + 1) -= 0x20;

    return res;
}

usa::string& usa::string::title_() {
    this->toLowerCase_();

    if (this->at(0) >= 0x61 && this->at(0) <= 0x7A)
        this->at(0) -= 0x20;

    if (!this->is_containSpace())
        if (!this->is_containAny(punctuation))
            return *this;

    for (const char& x : punctuation)
        for (int i = 0; i < this->size(); i++)
            if ((x == this->at(i) || this->at(i) == ' ') && i != this->size() - 1)
                if (this->at(i + 1) >= 0x61 && this->at(i + 1) <= 0x7A)
                    this->at(i + 1) -= 0x20;

    return *this;
}

usa::string usa::string::capitalize() const {
    usa::string res = *this;

    res.toLowerCase_();

    if (res.at(0) >= 0x61 && res.at(0) <= 0x7A)
        res.at(0) -= 0x20;

    if (!res.is_containAny(punctuation))
        return res;

    for (int i = 0; i < res.size(); i++)
        if (res.at(i) == '.' && i != res.size() - 1)
            if (res.at(i + 1) >= 0x61 && res.at(i + 1) <= 0x7A)
                res.at(i + 1) -= 0x20;

    return res;
}

usa::string& usa::string::capitalize_() {
    this->toLowerCase_();

    if (this->at(0) >= 0x61 && this->at(0) <= 0x7A)
        this->at(0) -= 0x20;

    if (!this->is_containAny(punctuation))
        return *this;

    for (int i = 0; i < this->size(); i++)
        if (this->at(i) == '.' && i != this->size() - 1)
            if (this->at(i + 1) >= 0x61 && this->at(i + 1) <= 0x7A)
                this->at(i + 1) -= 0x20;

    return *this;
}

usa::string usa::string::slice(int _start, int _end, int _step) const {
    usa::string res = *this;
    if (_step < -1)
        _start = exchangeX(++_end, ++_start);

    if (_start < 0)
        _start = (int(res.size()) + _start);
    if (_end == 0 || _end > int(res.size()))
        _end = (int(res.size()) - _start);
    else if (_end < 0)
        _end = (int(res.size()) + _end - _start);
    else
        _end = (_end - _start);

    res.assign(res.substr(_start, _end));
    res = (_step < 0) ? res.reverse() : res;

    if (_step != 0 && abs(_step) != 1)
    {
        std::string temp = "";

        int i = 0;
        while ((i * abs(_step)) < int(res.size()))
            temp += res.at(i++ * abs(_step));

        res.assign(temp);
    }

    return res;
}

usa::string& usa::string::slice_(int _start, int _end, int _step) {
    if (_step < -1)
        _start = exchangeX(++_end, ++_start);

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

template<typename ...Args>
usa::string usa::string::format(const Args& ...args) const {
    usa::string res = *this;
    const std::vector<usa::string>& arr = {args...};
    const int sz = arr.size();
    for (int i = 0; i < sz; i++) {
        res.replaceFirst_("{}", arr[i]);
        res.replace_(("{" + ItoS(i+1) + "}"), arr[i]);
    }
    return res;
}

template<typename ...Args>
usa::string& usa::string::format_(const Args& ...args) {
    const std::vector<usa::string>& arr = {args...};
    const int sz = arr.size();
    for (int i = 0; i < sz; i++) {
        this->replaceFirst_("{}", arr[i]);
        this->replace_(("{" + ItoS(i+1) + "}"), arr[i]);
    }
    return *this;
}

usa::string usa::string::reverse() const {
    usa::string res = *this;
    const int len = res.size();
    for (int i = 0; i < len / 2; i++)
        res.at(i) = exchangeX(res.at(len - 1 - i), res.at(i));
    return res;
}

usa::string& usa::string::reverse_() {
    const int len = this->size();
    for (int i = 0; i < len / 2; i++)
        this->at(i) = exchangeX(this->at(len - 1 - i), this->at(i));
    return *this;
}

vector<std::string> usa::string::split(const char &delimiter)
{
    if (count(delimiter) < 1) return {};
    
    vector<std::string> tokens;
    size_t start = 0, end = 0;
    
    while ((end = this->find(delimiter, start)) != std::string::npos)
    {
#if __cplusplus >= 201102L
        tokens.emplace_back(_trim(this->substr(start, end - start)));
#else
        tokens.emplace_back((this->substr(start, end - start)));
#endif
        start = end + 1;
    }
#if __cplusplus >= 201102L
    tokens.emplace_back(_trim(this->substr(start)));
#else
    tokens.emplace_back((this->substr(start)));
#endif
    return tokens;
}

vector<std::string> usa::string::splitlines() {
    return split('\n');
}

#if __cplusplus >= 201103L

    usa::string usa::string::ltrim() const {
        string s = (*this);
        s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
        return s;
    }

    usa::string usa::string::rtrim() const {
        string s = (*this);
        s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
        return s;
    }

    usa::string usa::string::trim() const {
        string s = (*this);
        s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
        s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
        return s;
    }

    usa::string& usa::string::ltrim_() {
        usa::string& s = (*this);
        s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
        return s;
    }

    usa::string& usa::string::rtrim_() {
        usa::string& s = (*this);
        s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
        return s;
    }

    usa::string& usa::string::trim_() {
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


    usa::string usa::string::replaceBlocks(const char* startsFrom, const std::string& endsOn, const char* replaceWith) const {
    usa::string res = *this;
    while (res.find(startsFrom) != std::string::npos) {
        std::size_t first = res.find(startsFrom);
        std::size_t sec = res.find(endsOn);
        res.replace_str(res.substr(first, (sec - first) + endsOn.size()), replaceWith);
    }
    return res;
}

usa::string& usa::string::replaceBlocks_(const char* startsFrom, const std::string& endsOn, const char* replaceWith) {
    while (this->find(startsFrom) != std::string::npos) {
        std::size_t first = this->find(startsFrom);
        std::size_t sec = this->find(endsOn);
        this->replace_str(this->substr(first, (sec - first) + endsOn.size()), replaceWith);
    }
    return *this;
}

usa::string usa::string::zfill(int width, char fillChar, bool fillFromStart) const {
    usa::string res = *this;
    if (res.size() < width)
    {
        int len = width - res.size();
        std::string _str = "";
        for (int i = 0; i < len; i++)
            _str += fillChar;
        res = (fillFromStart) ? _str + res : res + _str;
    }
    return res;
}

usa::string& usa::string::zfill_(int width, char fillChar, bool fillFromStart) {
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

usa::string usa::string::fill(int _start, int _end, char fillChar) const {
    usa::string res = *this;
    _end = (_end <= 0 || _end > res.size()) ? res.size() : _end;
    _start = (_start < 0 || _start >= _end) ? 0 : _start;
    for (int i = _start; i < _end; i++)
        res.at(i) = fillChar;
    return res;
}

usa::string& usa::string::fill_(int _start, int _end, char fillChar) {
    _end = (_end <= 0 || _end > this->size()) ? this->size() : _end;
    _start = (_start < 0 || _start >= _end) ? 0 : _start;
    for (int i = _start; i < _end; i++)
        this->at(i) = fillChar;
    return *this;
}

usa::string usa::string::toUpperCase() const {
    usa::string res = *this;
    for (char& ch : res)
        if (ch >= 0x61 && ch <= 0x7A)
            ch -= 0x20;
    return res;
}

usa::string& usa::string::toUpperCase_() {
    for (char& ch : *this)
        if (ch >= 0x61 && ch <= 0x7A)
            ch -= 0x20;
    return *this;
}

usa::string usa::string::toLowerCase() const {
    usa::string res = *this;
    for (char& ch : res)
        if (ch >= 0x41 && ch <= 0x5A)
            ch += 0x20;
    return res;
}

usa::string& usa::string::toLowerCase_() {
    for (char& ch : *this)
        if (ch >= 0x41 && ch <= 0x5A)
            ch += 0x20;
    return *this;
}

/// @c Done :):):) .....