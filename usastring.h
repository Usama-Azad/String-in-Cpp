///                           -*- @c C/C++ headers -*-

///                       -*- @c #include"usastring.h" -*-


/**
 * @author Usama Azad @c https://github.com/Usama-Azad
 * 
 * @file @c https://github.com/Usama-Azad/String-in-Cpp
 * 
 * @dependencies: @c usastringfunctool.h
**/


/**
 * 
 * MIT License
 *
 * Copyright (c) 2020 usastring, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
**/



#ifndef __str_H__
#define __str_H__ 1

#ifdef __cplusplus

#define __version__ "3.0.0"
#define __author__ "Usama Azad"

#include "usastringfunctool.h"


#define NONE            ""
#define digits          "0123456789"
#define octdigits       "01234567"
#define hexdigits       "0123456789abcdefABCDEF"
#define operators       "+-*/^%!&|"
#define punctuation     "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"
#define ascii_letters   "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ascii_lowercase "abcdefghijklmnopqrstuvwxyz"
#define ascii_uppercase "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define printable       "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"


/// package name usa
namespace usa
{
    /// string class under package usa => ~90 methods
    class string final : public std::string
    {

        typedef              int                   __INT__;
        typedef              bool                  __BOOL__;
        typedef              long                  __LONG__;
        typedef              char                  __CHAR__;
        typedef              float                 __FLOAT__;
        typedef              double                __DOUBLE__;
        typedef              long double           __LDOUBLE__;
        typedef              usa::string           __MYSTRING__;
        typedef              std::string           __STDSTRING__;
        typedef              usa::string&          __MYSTRING_REF__;

        __STDSTRING__ Lower_Case(__STDSTRING__ str) const;

        __MYSTRING_REF__ replace_ch(const __CHAR__ &_old, const __CHAR__ &_new, __BOOL__ first = false);

        __MYSTRING_REF__ replace_str(const __STDSTRING__& _old, const __STDSTRING__& _new, __BOOL__ first = false);

    public:

        /***********************************************************************
         * @c different constructors for class string to create string from
         *    different data types.
        ************************************************************************/

        string()                             : std::string() {}

        string(const char *str)              : std::string(str) {}

        string(const __STDSTRING__ &str)     : std::string(str) {}

        string(const __BOOL__ &val)          : std::string(BtoS(val)) {}

        string(const __CHAR__ &val)          : std::string(CtoS(val)) {}

        string(const __DOUBLE__ &val)        : std::string(DtoS(val)) {}

        string(const __FLOAT__ &val)         : std::string(FtoS(val)) {}

        string(const __LDOUBLE__ &val)       : std::string(LDtoS(val)) {}

        string(const __INT__ &val)           : std::string(to_string(val)) {}

        string(const __LONG__ &val)          : std::string(to_string(val)) {}

        template<typename type>
        string(const std::initializer_list<type> &val)
        {
            __STDSTRING__ res = "";
            for (const type &i : val)
                res += string(i);
            this->assign(res);
        }

        /************************************************************************/



        /***********************************************************************
         * @c different operators and other function for converting string to
         *    different data types.
        ************************************************************************/
        operator int() const;

        operator long() const;

        operator bool() const;

        operator char() const;

        operator float() const;

        operator double() const;

        operator long double() const;

        operator std::string() const;

        explicit operator const char *() const;

        __INT__         to_int() const;
          
        __LONG__        to_long() const;

        __BOOL__        to_bool() const;
        
        __CHAR__        to_char() const;

        __FLOAT__       to_float() const;
        
        __DOUBLE__      to_double() const;

        __LDOUBLE__     to_longDouble() const;
        
        __STDSTRING__   to_stdString() const;

        template<typename T>
        T castTo() const {
            T var;
            stringstream s;
            try {
                s << (*this);
                s >> var;
                return var;
            } catch (...) {
                throw std::runtime_error("error: Type casting is not possible.");
            }
        }

        /************************************************************************/



        /***********************************************************************
         * @c Some others operators.
        ************************************************************************/

        __MYSTRING__ operator*(int times) const
        {
            __MYSTRING__ res = *this;
            times = (times < 0) ? abs(times) : (times == 0) ? 1 : times;
            for (; --times;)
                res.append(*this);
            return res;
        }

        __MYSTRING_REF__ operator*=(int times)
        {
            const __MYSTRING_REF__ res = *this;
            times = (times < 0) ? abs(times) : (times == 0) ? 1 : times;
            for (; --times;)
                this->append(res);
            return *this;
        }

        template<typename T>
        __MYSTRING_REF__ operator<<(const T& obj) {
            return this->join(string(obj));
        }

        __MYSTRING__ operator~() const {
            return this->reverse();
        }

        /************************************************************************/



        /***********************************************************************
         * @name is_space
         * @brief A string is whitespace if all characters in the string
         * are whitespace and string is not empty.
         * @return bool : Return true if the string is a whitespace string, 
         * else false.
        ************************************************************************/
        __BOOL__ is_space() const;
        /************************************************************************/
        

        /***********************************************************************
         * @name is_upper
         * @brief A string is uppercase if all cased characters in a string 
         * are uppercase and string is not empty.
         * @return bool : Return true if the string is an uppercase string, 
         * else false.
        ************************************************************************/
        __BOOL__ is_upper() const;
        /************************************************************************/
        

        /***********************************************************************
         * @name is_lower
         * @brief A string is lowercase if all cased characters in the string 
         * are lowercase and string is not empty.
         * @return bool : Return true if the string is a lowercase string, 
         * else false.
        ************************************************************************/
        __BOOL__ is_lower() const;
        /************************************************************************/


        /***********************************************************************
         * @name is_alpha
         * @brief A string is alphabetic if all characters in the string are 
         * alphabetic and string is not empty.
         * @return bool : Return true if the string is an alphabetic string, 
         * else false.
        ************************************************************************/
        __BOOL__ is_alpha() const;
        /************************************************************************/


        /***********************************************************************
         * @name is_alnum
         * @brief A string is alpha Numeric if all characters in the string are
         *  alpha Numeric and string is not empty.
         * @return bool : Return true if the string is an alpha Numeric string,
         * else false.
        ************************************************************************/
        __BOOL__ is_alnum() const;
        /************************************************************************/


        /***********************************************************************
         * @name is_numeric
         * @brief A string is numeric if all characters in the string are numeric
         * and and string is not empty.
         * @return bool : Return true if the string is a numeric string,
         * else false.
        ************************************************************************/
        __BOOL__ is_numeric() const;
        /************************************************************************/

        
        /***********************************************************************
         * TODO Add optional arguments start and end for slicing.
         * @name is_containSpace
         * @return bool : Return true if any char in string is space,
         * else false.
        ************************************************************************/
        __BOOL__ is_containSpace() const;
        /************************************************************************/


        /***********************************************************************
         * TODO Add optional arguments start and end for slicing.
         * @name is_containAny
         * @brief take no. of chars are return true if string contains any of those chars,
         * else false.
         * @param str: string of different characters.
         * @example usa::string("C++ is awesome!").is_containAny(punctuation);
         * @return bool : Return true if the string contains any of those characters,
         * else false.
        ************************************************************************/
        __BOOL__ is_containAny(const char* str) const;
        /************************************************************************/


        /***********************************************************************
         * @name is_palindrome
         * @brief A string is palindrome if it reads the same backward as forward.
         * @return bool : Return true if the string is palindrome, else false.
        ************************************************************************/
        __BOOL__ is_palindrome() const { return (*this) == this->reverse(); }
        /************************************************************************/


        /***********************************************************************
         * @name isEmpty
         * @brief A string is empty if it is "".
         * @return bool : Return true if the string is empty, else false.
        ************************************************************************/
        __BOOL__ isEmpty() const { return (*this) == ""; }
        /************************************************************************/


        /***********************************************************************
         * TODO Add optional arguments start and end for slicing.
         * @name endswith
         * @param str: suffix which is to be compared.
         * @param match_case: (By default 'true') if true then compared cases 
         * of the character with the charcter present in orignal string, 
         * but if it is false then only characters are compared without comparing 
         * the case of character.
         * @return bool : Return true if string ends with the specified suffix,
         * else false.
        ************************************************************************/
        __BOOL__ endswith(const __STDSTRING__ &str, __BOOL__ match_case = true) const;
        /************************************************************************/


        /***********************************************************************
         * TODO Add optional arguments start and end for slicing.
         * @name startswith
         * @param str: suffix which is to be compared.
         * @param match_case: (By default 'true') if true then compared cases
         * of the character with the charcter present in orignal string,
         * but if it is false then only characters are compared without comparing
         * the case of character.
         * @return bool : Return true if string starts with the specified suffix,
         * else false.
        ************************************************************************/
        __BOOL__ startswith(const __STDSTRING__ &str, __BOOL__ match_case = true) const;
        /************************************************************************/


        /***********************************************************************
         * @name findStr
         * @param str: substring which is to be compared.
         * @param pos: position from where start comparasion.
         * @param match_case: (By default 'true') if true then compared cases
         * of the character with the charcter present in orignal string,
         * but if it is false then only characters are compared without comparing
         * the case of character.
         * @return int : Return the lowest index in string where substring is found,
         * Return -1 on failure.
        ************************************************************************/
        __INT__ findStr(const __STDSTRING__ &str, __INT__ pos = 0, __BOOL__ match_case = true) const;
        /************************************************************************/


        /***********************************************************************
         * TODO Add optional arguments start and end for slicing.
         * @name count
         * @name countWord
         * @param ch: character which occurrences count from the given string.
         * @return int : Return the number of occurrences of character @c 'ch'
         * in string.
        ************************************************************************/
        __INT__ count(const __CHAR__ &ch) const;
        __INT__ countWord(__MYSTRING__ word, bool match_case = true) const;
        /************************************************************************/


        /***********************************************************************
         * @name getLine
         * @brief String extraction, Read value from given stream and 
         * stores it into string.
         * @param in: Input stream from where function reads the buffer 
         * (like 'cin' for read buffer from console).
         * @param delim: Character marking end of line. (By default '\n')
         * @param msgToBeDisplay: if given then it printed on console before
         * taking input from console.
         * @return usa::string& : Return a refrence of input string.
        ************************************************************************/
        template<typename T>
        __MYSTRING_REF__ getLine(basic_istream<__CHAR__, T>& in, __CHAR__ delim = 0x00A, const char* msgToBeDisplay = NULL)
        {
            if (msgToBeDisplay != NULL)
                printf(msgToBeDisplay);
            fflush(stdin); // Flush the input stream Buffer.
            getline(in, *this, delim); // Reading buffer from Stream.
            return *this;
        }
        /************************************************************************/


        /***********************************************************************
         * @name join
         * @overload +2
         * @brief Concatenate given string object with orignal string with delimeter.
         * @param obj: An other string object.
         * @param delimiter: By which two strings are joined. (By default "")
         * @return usa::string& : Return a refrence of Concatenated string.
        ************************************************************************/
        __MYSTRING_REF__ join(const __MYSTRING__& obj, const std::string& delimiter = "") {
            (*this) += (delimiter + obj);
            return *this;
        }
        /************************************************************************/



        /***********************************************************************
         * @name join
         * @overload +2
         * @brief Concatenate Array of <T> with orignal string with delimeter.
         * @tparam T: Type of Array.
         * @tparam n: Size of Array.
         * @param arr: Array of 'type' <T> with 'size' <n>
         * @param delimiter: By which two strings are joined. (By default "")
         * @param swd: start with delimeter if it is true concatination starts with
         * delimeter, else start with first element of array (By default 'true')
         * @return usa::string& : Return a refrence of Concatenated string.
        ************************************************************************/
        template <typename T, size_t n>
        __MYSTRING_REF__ join(const T(&arr)[n], const std::string &delimiter = "", __BOOL__ swd = true)
        {
            for (int i = 0; i < n; i++)
                (*this) += (swd) ? delimiter + string(arr[i]) : string(arr[i]) + delimiter;
            return *this;
        }
        /************************************************************************/


        /***********************************************************************
         * @name join
         * @overload +2
         * @brief Concatenate Sequence with orignal string with delimeter.
         * @tparam Iter: Type of Iterator.
         * @param delimiter: By which two strings are joined. (By default "")
         * @param swd: start with delimeter if it is true concatination starts with
         * delimeter, else start with first element of iterator (By default 'true')
         * @return usa::string& : Return a refrence of Concatenated string.
        ************************************************************************/
        template <typename Iter>
        __MYSTRING_REF__ join(Iter first, Iter last, const std::string& delimiter = "", __BOOL__ swd = true) {
            for (; first != last; first++)
                *this += swd ? delimiter + string(*first) : string(*first) + delimiter;
            return *this;
        }
        /************************************************************************/



#if __cplusplus >= 201102L

        /***********************************************************************
         * TODO If chars is given, remove characters from string instead.
         * @name trim, ltrim, rtrim
         * @return usa::string : Return a new string with leading
         * and trailing whitespace remove.         
         * 
         * @name trim_, ltrim_, rtrim_, @deprecated strip
         * @return usa::string& : Return a refrence to the string with leading
         * and trailing whitespace remove.
         *
         * @ltrim: it only trims only left spaces.
         * @rtrim: it only trims only right spaces.
         * @trim: it trims spaces from both sides.
         * @strip: it works like @b trim() but it does not return any thing.
        ************************************************************************/
        __MYSTRING__ trim()  const;

        __MYSTRING__ ltrim() const;

        __MYSTRING__ rtrim() const;

        __MYSTRING_REF__ trim_();

        __MYSTRING_REF__ ltrim_();

        __MYSTRING_REF__ rtrim_();

        /**
         * Deprecated in version 3.0.0.
         * @deprecated Use trim_() instead of this.
        **/
        void strip();

        /************************************************************************/

#endif


        /***********************************************************************
         * @name title
         * @return usa::string | usa::string& : Return a string where each word is titlecased.
         *
         * @brief words start with uppercased characters and all remaining cased
         * characters have lower case.
        ************************************************************************/
        __MYSTRING__ title() const;
        __MYSTRING_REF__ title_();
        /************************************************************************/


        /***********************************************************************
         * @name reverse
         * @return usa::string | usa::string& : Return a reversed string.
        ************************************************************************/
        __MYSTRING__ reverse() const;
        __MYSTRING_REF__ reverse_();
        /************************************************************************/


        /***********************************************************************
         * @name swapcase
         * @brief Convert uppercase characters to lowercase and lowercase 
         * characters to uppercase.
         * @return usa::string | usa::string& : Return a swapcased string.
        ************************************************************************/
        __MYSTRING__ swapcase() const;
        __MYSTRING_REF__ swapcase_();
        /************************************************************************/


        /***********************************************************************
         * @name capitalize
         * @brief make the first character upper case and the rest lower case.
         * @return usa::string | usa::string& : Return a capitalized string.
        ************************************************************************/
        __MYSTRING__ capitalize() const;
        __MYSTRING_REF__ capitalize_();
        /************************************************************************/


        /***********************************************************************
         * @name toUpperCase
         * @brief all character in given string are converted into upper case.
         * @return usa::string | usa::string& : Return a UpperCased string.
        ************************************************************************/
        __MYSTRING__ toUpperCase() const;
        __MYSTRING_REF__ toUpperCase_();
        /************************************************************************/


        /***********************************************************************
         * @name toLowerCase
         * @brief all character in given string are converted into lower case.
         * @return usa::string | usa::string& : Return a LowerCased string.
        ************************************************************************/
        __MYSTRING__ toLowerCase() const;
        __MYSTRING_REF__ toLowerCase_();
        /************************************************************************/


        /***********************************************************************
         * @name replaceBlocks
         * @brief replace all matching blocks in the string.
         * @param startsFrom: Starting point of the block.
         * @param endsOn: Ending point of the block.
         * @param replaceWith: String which is replaced by all blocks.
         * @return usa::string | usa::string& : Return a string with all matching blocks
         * are replaced by @p replaceWith.
        ************************************************************************/
        __MYSTRING__ replaceBlocks(const __CHAR__* startsFrom, const __STDSTRING__& endsOn, const __CHAR__* replaceWith) const;
        __MYSTRING_REF__ replaceBlocks_(const __CHAR__* startsFrom, const __STDSTRING__& endsOn, const __CHAR__* replaceWith);
        /************************************************************************/


        /***********************************************************************
         * @name replace
         * @brief replace all @c _old substrings in given string with @c _new substring.
         * @param _old: substring which is already present in the string.
         * @param _new: new substring which is replace with all @c _old substrings
         * in the string.
         * @return usa::string | usa::string& : Return a refrence string with all
         * occurrences of @c _old substrings replaced by @c _new substring.
        ************************************************************************/
        __MYSTRING__ replace(const __STDSTRING__ &_old, const __STDSTRING__ &_new) const;
        __MYSTRING_REF__ replace_(const __STDSTRING__ &_old, const __STDSTRING__ &_new);
        /************************************************************************/


        /***********************************************************************
         * @name replaceFirst
         * @brief replace only first occurrences of @c _old substring in given
         * string with @c _new substring.
         * @param _old: substring which is already present in the string.
         * @param _new: new substring which is replace with only first occurrences of
         * @c _old substring in the string.
         * @return usa::string | usa::string& : Return a string with only first 
         * occurrences of @c _old substring replaced by @c _new substring.
        ************************************************************************/
        __MYSTRING__ replaceFirst(const __STDSTRING__ &_old, const __STDSTRING__ &_new) const;
        __MYSTRING_REF__ replaceFirst_(const __STDSTRING__ &_old, const __STDSTRING__ &_new);
        /************************************************************************/


        /***********************************************************************
         * @name format
         * @brief Formatted string, using substitutions from args.
         * The substitutions are identified by braces ('{' and '}').
         * After version 3.0.0 now support index substitutions (like "Hello {2} & {1}").
         * @tparam ...Args: Any type of args.
         * @param args: Different type of args.
         * @return usa::string | usa::string& : Return a formatted version of string.
        ************************************************************************/
        template<typename ...Args>
        __MYSTRING__ format(const Args& ...) const; 

        template<typename ...Args>
        __MYSTRING_REF__ format_(const Args& ...);
        /************************************************************************/


        /***********************************************************************
         * @name fill
         * @brief fill given @c fillChar in string from @c _start to @c _end.
         * @param _start: position from where start filling.
         * @param _end: position where filling ends.
         * @return usa::string | usa::string& : Return a fill string with 
         * @c fillChar from @c _start to @c _end.
        ************************************************************************/
        __MYSTRING__ fill(__INT__ _start, __INT__ _end, __CHAR__ fillChar) const;
        __MYSTRING_REF__ fill_(__INT__ _start, __INT__ _end, __CHAR__ fillChar);
        /************************************************************************/


        /***********************************************************************
         * @name zfill
         * @brief Pad a numeric string with @c fillChar on the left or right,
         * to fill a field of the given @c width.
         * @param width: how much paddind is required.
         * @param fillChar: character which is filled during padding. (By default '0')
         * @param fillFromStart: if true so start padding from start or left side of 
         * the string, else start padding from end or right side of the string. (By default 'true')
         * @return usa::string | usa::string& : Return a padded string.
        ************************************************************************/
        __MYSTRING__ zfill(__INT__ width, __CHAR__ fillChar = 0x30, __BOOL__ fillFromStart = true) const;
        __MYSTRING_REF__ zfill_(__INT__ width, __CHAR__ fillChar = 0x30, __BOOL__ fillFromStart = true);
        /************************************************************************/


        /***********************************************************************
         * @name slice
         * @brief Advance extended String slicing.
         * 
         * @param _start: from where start the slicing of string (It might be negative).
         * @param _end: from where slicing ends (It might be negative).
         * @param _step: how many characters skiped during slicing (It might be negative).
         * @return usa::string | usa::string& : Return a sliced string.
        ************************************************************************/
        __MYSTRING__ slice(__INT__ _start = 0, __INT__ _end = 0, __INT__ _step = 0) const;
        __MYSTRING_REF__ slice_(__INT__ _start = 0, __INT__ _end = 0, __INT__ _step = 0);
        /************************************************************************/


        /***********************************************************************
         * @name split
         * @brief Return a vector of the words in the string, using the delimiter to split the string.
         * The default value of delimiter 0x020 means split according to any whitespace.
         * 
         * @param delimiter: By which function split the given string (By default ' ').
         * @return vector std::string : Return a vector of splited tokens of string.
        ************************************************************************/
        vector<__STDSTRING__> split(const __CHAR__& delimiter = 0x020);
        /************************************************************************/


        /***********************************************************************
         * @name splitlines
         * @brief use the split function with (delimiter = "\n") so it splits the
         * string with every newline character.
         * 
         * @return vector std::string : Return a vector of splited tokens of string.
        ************************************************************************/
        vector<__STDSTRING__> splitlines();
        /************************************************************************/

    }; // string

} // namespace usa



#if __cplusplus > 201103L

    #pragma GCC diagnostic ignored "-Wliteral-suffix"

    #if __cplusplus >= 201402L

        /***********************************************************************
         * @name user defined literal
         * @brief user defined literal for usa::string after C++11.
         *
         * @return usa::string || std::string : if  you have C++14 or above it
         * Return <usa::string> otherwise Return <std::string>
        ************************************************************************/
        usa::string operator""x(const char* str, size_t size) {
            return usa::string(str);
        }

    #else

        /***********************************************************************
         * @name user defined literal
         * @brief user defined literal for usa::string after C++11.
         *
         * @return usa::string || std::string : if  you have C++14 or above it
         * Return <usa::string> otherwise Return <std::string>
        ************************************************************************/
        std::string operator""x(const char* str, size_t size) {
            return std::string(str);
        }

    #endif

#endif


#include "Resources/reststoi.tcc"

#endif // __cplusplus

#endif // __str_H__