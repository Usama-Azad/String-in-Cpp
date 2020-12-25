///                           -*- @c C/C++ headers -*-

///                        -*- @c #include"usastring.h" -*-



/**
 * @author Usama Azad @c <https://github.com/Usama-Azad>
 * 
 * @dependencies: [ "usastringfunctool.h" ]
 * 
 * This @c header is distributed in the hope that it will be useful,
 * but @a WITHOUT_ANY_WARRANTY; without even the implied @c warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
**/


/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
**/



#ifndef __str_H__
#define __str_H__ 1

#ifdef __cplusplus

#define __version__ "1.0.0"
#define __author__ "Usama Azad"

#include "usastringfunctool.h"


#define NONE            ""
#define digits          "0123456789"
#define octdigits       "01234567"
#define hexdigits       "0123456789abcdefABCDEF"
#define operators       "+-*/^%!&|"
#define printable       "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"
#define punctuation     "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"
#define special_chars   "#&$!%@?~^|<>(){}[]+-*\\/=_.,:;`'\""
#define ascii_letters   "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ascii_lowercase "abcdefghijklmnopqrstuvwxyz"
#define ascii_uppercase "ABCDEFGHIJKLMNOPQRSTUVWXYZ"



namespace usa
{

    class string final : public std::string
    {

        typedef              int                   __INT__;
        typedef              bool                  __BOOL__;
        typedef              long                  __LONG__;
        typedef              char                  __CHAR__;
        typedef              float                 __FLOAT__;
        typedef              double                __DOUBLE__;
        typedef              long double           __LDOUBLE__;
        typedef              std::string           __STDSTRING__;
        typedef              usa::string&          __MYSTRING_REF__;

        __STDSTRING__ Lower_Case(__STDSTRING__ str);

        __MYSTRING_REF__ replace_ch(__CHAR__ _old, __CHAR__ _new, __BOOL__ first = false);

        __MYSTRING_REF__ replace_str(__STDSTRING__ _old, __STDSTRING__ _new, __BOOL__ first = false);

    public:

        /***********************************************************************
         * @c different constructors for class string to create string from
         *    different data types.
        ************************************************************************/

        string()                            : std::string() {}

        string(const char *str)             : std::string(str) {}

        string(const __STDSTRING__ str)     : std::string(str) {}

        string(const __BOOL__ val)          : std::string(BtoS(val)) {}

        string(const __CHAR__ val)          : std::string(CtoS(val)) {}

        string(const __DOUBLE__ val)        : std::string(DtoS(val)) {}

        string(const __FLOAT__ val)         : std::string(FtoS(val)) {}

        string(const __LDOUBLE__ val)       : std::string(LDtoS(val)) {}

        string(const __INT__ val)           : std::string(to_string(val)) {}

        string(const __LONG__ val)          : std::string(to_string(val)) {}

        template<typename type>
        string(const std::initializer_list<type> val)
        {
            __STDSTRING__ res = "";
            for (auto i : val)
                res += string(i);
            this->assign(res);
        }

        /************************************************************************/



        /***********************************************************************
         * @c different operators and other function for converting string into
         *    different data types.
        ************************************************************************/
        operator int();

        operator long();

        operator bool();

        operator char();

        operator float();

        operator double();

        operator long double();

        operator std::string();

        explicit operator const char* ();

        __INT__         to_int();                           
          
        __LONG__        to_long();                         

        __BOOL__        to_bool();                         
        
        __CHAR__        to_char();                        

        __FLOAT__       to_float();                       
        
        __DOUBLE__      to_double();                     

        __LDOUBLE__     to_longdouble();            
        
        __STDSTRING__   to_std_string();    

        template<typename T>
        T convert()
        {
            T var;
            stringstream s;
            try
            {
                s << (*this);
                s >> var;
                return var;
            }
            catch (...)
            {
                throw std::runtime_error("error: conversion is not possible.");
            }
        }

        /************************************************************************/

        

        /***********************************************************************
         * @name is_space
         * @brief A string is whitespace if all characters in the string
         * are whitespace and string is not empty.
         * @return bool : Return true if the string is a whitespace string, 
         * else false.
        ************************************************************************/
        __BOOL__ is_space();
        /************************************************************************/
        

        /***********************************************************************
         * @name is_upper
         * @brief A string is uppercase if all cased characters in a string 
         * are uppercase and string is not empty.
         * @return bool : Return true if the string is an uppercase string, 
         * else false.
        ************************************************************************/
        __BOOL__ is_upper();
        /************************************************************************/
        

        /***********************************************************************
         * @name is_lower
         * @brief A string is lowercase if all cased characters in the string 
         * are lowercase and string is not empty.
         * @return bool : Return true if the string is a lowercase string, 
         * else false.
        ************************************************************************/
        __BOOL__ is_lower();
        /************************************************************************/


        /***********************************************************************
         * @name is_alpha
         * @brief A string is alphabetic if all characters in the string are 
         * alphabetic and string is not empty.
         * @return bool : Return true if the string is an alphabetic string, 
         * else false.
        ************************************************************************/
        __BOOL__ is_alpha();
        /************************************************************************/


        /***********************************************************************
         * @name is_alnum
         * @brief A string is alpha Numeric if all characters in the string are
         *  alpha Numeric and string is not empty.
         * @return bool : Return true if the string is an alpha Numeric string,
         * else false.
        ************************************************************************/
        __BOOL__ is_alnum();
        /************************************************************************/


        /***********************************************************************
         * @name is_numeric
         * @brief A string is numeric if all characters in the string are numeric
         * and and string is not empty.
         * @return bool : Return true if the string is a numeric string,
         * else false.
        ************************************************************************/
        __BOOL__ is_numeric();
        /************************************************************************/

        
        /***********************************************************************
         * TODO Add optional arguments start and end for slicing.
         * @name is_contain_space
         * @return bool : Return true if any char in string is space,
         * else false.
        ************************************************************************/
        __BOOL__ is_contain_space();
        /************************************************************************/


        /***********************************************************************
         * TODO Add optional arguments start and end for slicing.
         * @name is_contain
         * @brief take type of chars are return true if string contain those chars,
         * else false.
         * @param type: contain which type of character. (By default 'special_chars')
         * @example usa::string("C++ is awesome!").is_contain(punctuation);
         * @return bool : Return true if the string contains given type of characters,
         * else false.
        ************************************************************************/
        __BOOL__ is_contain(const char* type = special_chars);
        /************************************************************************/


        /***********************************************************************
         * @name is_None
         * @brief A string is None if it is empty.
         * @return bool : Return true if the string is empty, else false.
        ************************************************************************/
        __BOOL__ is_None() const { return (*this) == ""; }
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
        __BOOL__ endswith(__STDSTRING__ str, __BOOL__ match_case = true);
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
        __BOOL__ startswith(__STDSTRING__ str, __BOOL__ match_case = true);
        /************************************************************************/


        /***********************************************************************
         * @name find_str
         * @param str: substring which is to be compared.
         * @param pos: position from where start comparasion.
         * @param match_case: (By default 'true') if true then compared cases
         * of the character with the charcter present in orignal string,
         * but if it is false then only characters are compared without comparing
         * the case of character.
         * @return int : Return the lowest index in string where substring is found,
         * Return -1 on failure.
        ************************************************************************/
        __INT__ find_str(__STDSTRING__ str, __INT__ pos = 0, __BOOL__ match_case = true);
        /************************************************************************/


        /***********************************************************************
         * TODO Add optional arguments start and end for slicing.
         * @name count
         * @param ch: character which occurrences count from the given string.
         * @return int : Return the number of occurrences of character @c 'ch'
         * in string.
        ************************************************************************/
        __INT__ count(__CHAR__ ch);
        /************************************************************************/


        /***********************************************************************
         * @name getLine
         * @brief String extraction, Read value from given stream and 
         * stores it into string.
         * @param in: A character array in which to store the data.
         * @param delim: A "stop" character. (By default 'newline')
         * @param msgtobeprint: if given then it printed on console before
         * taking input from console.
         * @return usa::string& : Return a refrence of input string.
        ************************************************************************/
        template<typename T>
        __MYSTRING_REF__ getLine(basic_istream<__CHAR__, T>& in, __CHAR__ delim = 0x00A, const char* msgtobeprint = NULL)
        {
            if (msgtobeprint != NULL)
                std::cout << msgtobeprint;
            fflush(stdin);
            getline(in, *this, delim);
            return *this;
        }
        /************************************************************************/



        /***********************************************************************
         * @name join
         * @overload +6
         * @brief Concatenate array of string with orignal string with delimeter.
         * @param arr: Array of string.
         * @param delimiter: By which two strings are joined. (By default "")
         * @param swd: start with delimeter if it is true concatination starts with
         * delimeter, else start with given array's element (By default 'true')
         * @return usa::string& : Return a refrence of Concatenated string.
        ************************************************************************/
        template <size_t n>
        __MYSTRING_REF__ join(string(&arr)[n], string delimiter = "", __BOOL__ swd = true)
        {
            for (int i = 0; i < n; i++)
                if (swd)
                    (*this) += delimiter + arr[i];
                else
                    (*this) += arr[i] + delimiter;
            return *this;
        }
        /************************************************************************/


        /***********************************************************************
         * @name join
         * @overload +6
         * @brief Concatenate array of std::string with orignal string with delimeter.
         * @param arr: Array of std::string.
         * @param delimiter: By which two strings are joined. (By default "")
         * @param swd: start with delimeter if it is true concatination starts with
         * delimeter, else start with given array's element (By default 'true')
         * @return usa::string& : Return a refrence of Concatenated string.
        ************************************************************************/
        template <size_t n>
        __MYSTRING_REF__ join(__STDSTRING__(&arr)[n], string delimiter = "", __BOOL__ swd = true)
        {
            for (int i = 0; i < n; i++)
                if (swd)
                    (*this) += delimiter + arr[i];
                else
                    (*this) += arr[i] + delimiter;
            return *this;
        }
        /************************************************************************/



#if __cplusplus >= 201102L

        /***********************************************************************
         * TODO If chars is given, remove characters from string instead.
         * @name trim, ltrim, rtrim, strip
         * @return usa::string& : Return a refrence of the string with leading
         * and trailing whitespace remove.
         *
         * @ltrim: it only trims only left spaces.
         * @rtrim: it only trims only right spaces.
         * @trim: it trims spaces from both sides.
         * @strip: it works like trim() but it does not return any thing.
        ************************************************************************/
        void strip();
        
        __MYSTRING_REF__ trim();

        __MYSTRING_REF__ ltrim();

        __MYSTRING_REF__ rtrim();

        /************************************************************************/

#endif


        /***********************************************************************
         * @name title
         * @return usa::string& : Return a refrence of the string where each
         * word is titlecased.

         * @brief words start with uppercased characters and all remaining cased
         * characters have lower case.
        ************************************************************************/
        __MYSTRING_REF__ title();
        /************************************************************************/


        /***********************************************************************
         * @name reverse
         * @return usa::string& : Return a refrence of the reversed string.
        ************************************************************************/
        __MYSTRING_REF__ reverse();
        /************************************************************************/


        /***********************************************************************
         * @name swapcase
         * @brief Convert uppercase characters to lowercase and lowercase 
         * characters to uppercase.
         * @return usa::string& : Return a refrence of the swapcased string.
        ************************************************************************/
        __MYSTRING_REF__ swapcase();
        /************************************************************************/


        /***********************************************************************
         * @name capitalize
         * @brief make the first character upper case and the rest lower case.
         * @return usa::string& : Return a refrence of the capitalized string.
        ************************************************************************/
        __MYSTRING_REF__ capitalize();
        /************************************************************************/


        /***********************************************************************
         * @name toUpperCase
         * @brief all character in given string are converted into upper case.
         * @return usa::string& : Return a refrence of the UpperCased string.
        ************************************************************************/
        __MYSTRING_REF__ toUpperCase();
        /************************************************************************/


        /***********************************************************************
         * @name toLowerCase
         * @brief all character in given string are converted into lower case.
         * @return usa::string& : Return a refrence of the LowerCased string.
        ************************************************************************/
        __MYSTRING_REF__ toLowerCase();
        /************************************************************************/


        /***********************************************************************
         * @name replace
         * @overload +1
         * @brief replace all @c _old characters in given string with @c _new char.
         * @param _old: char which is already present in the string.
         * @param _new: new char which is replace with all @c _old chars in the string.
         * @return usa::string& : Return a refrence string with all occurrences
         * of @c _old character replaced by @c _new character.
        ************************************************************************/
        __MYSTRING_REF__ replace(__CHAR__ _old, __CHAR__ _new);
        /************************************************************************/


        /***********************************************************************
         * @name replace_first
         * @overload +1
         * @brief replace only first occurrences of @c _old characters in given
         * string with @c _new char.
         * @param _old: char which is already present in the string.
         * @param _new: new char which is replace with only first occurrences of
         * @c _old chars in the string.
         * @return usa::string& : Return a refrence string with only first occurrences
         * of @c _old character replaced by @c _new character.
        ************************************************************************/
        __MYSTRING_REF__ replace_first(__CHAR__ _old, __CHAR__ _new);
        /************************************************************************/


        /***********************************************************************
         * @name replace
         * @overload +1
         * @brief replace all @c _old substrings in given string with @c _new substring.
         * @param _old: substring which is already present in the string.
         * @param _new: new substring which is replace with all @c _old substrings
         * in the string.
         * @return usa::string& : Return a refrence string with all occurrences
         * of @c _old substrings replaced by @c _new substring.
        ************************************************************************/
        __MYSTRING_REF__ replace(__STDSTRING__ _old, __STDSTRING__ _new);
        /************************************************************************/


        /***********************************************************************
         * @name replace_first
         * @overload +1
         * @brief replace only first occurrences of @c _old substring in given
         * string with @c _new substring.
         * @param _old: substring which is already present in the string.
         * @param _new: new substring which is replace with only first occurrences of
         * @c _old substring in the string.
         * @return usa::string& : Return a refrence string with only first occurrences
         * of @c _old substring replaced by @c _new substring.
        ************************************************************************/
        __MYSTRING_REF__ replace_first(__STDSTRING__ _old, __STDSTRING__ _new);
        /************************************************************************/


        /***********************************************************************
         * @name format
         * @brief Formatted string, using substitutions from std::vector of string.
         * The substitutions are identified by braces ('{' and '}').
         * @param arr: const vector<string>& of different args.
         * @return usa::string& : Return a formatted version of string.
        ************************************************************************/
        __MYSTRING_REF__ format(const std::vector<string>& arr);
        /************************************************************************/


        /***********************************************************************
         * @name fill
         * @brief fill given @c fillChar in string from @c _start to @c _end.
         * @param _start: position from where start filling.
         * @param _end: position where filling ends.
         * @return usa::string& : Return a refrence of fill string with @c fillChar
         * from @c _start to @c _end.
        ************************************************************************/
        __MYSTRING_REF__ fill(__INT__ _start, __INT__ _end, __CHAR__ fillChar);
        /************************************************************************/


        /***********************************************************************
         * @name zfill
         * @brief Pad a numeric string with @c fillChar on the left or right,
         * to fill a field of the given @c width.
         * @param width: how much paddind is required.
         * @param fillChar: character which is filled during padding. (By default '0')
         * @param fillFromStart: if true so start padding from start or left side of 
         * the string, else start padding from end or right side of the string. (By default 'true')
         * @return usa::string& : Return a refrence of padded string.
        ************************************************************************/
        __MYSTRING_REF__ zfill(__INT__ width, __CHAR__ fillChar = '0', __BOOL__ fillFromStart = true);
        /************************************************************************/


        /***********************************************************************
         * @name join
         * @overload +6
         * @brief Concatenate given string object with orignal string with delimeter.
         * @param obj: An other string object.
         * @param delimiter: By which two strings are joined. (By default "")
         * @return usa::string& : Return a refrence of Concatenated string.
        ************************************************************************/
        __MYSTRING_REF__ join(const usa::string& obj, string delimiter = "");
        /************************************************************************/


        /***********************************************************************
         * @name join
         * @overload +6
         * @brief Concatenate vector of characters with orignal string with delimeter.
         * @param arr: Vector of characters.
         * @param delimiter: By which two strings are joined. (By default "")
         * @param swd: start with delimeter if it is true concatination starts with
         * delimeter, else start with given vactor's element (By default 'true')
         * @return usa::string& : Return a refrence of Concatenated string.
        ************************************************************************/
        __MYSTRING_REF__ join(std::vector<__CHAR__> arr, string delimiter = "", __BOOL__ swd = true);
        /************************************************************************/


        /***********************************************************************
         * @name join
         * @overload +6
         * @brief Concatenate vector of string with orignal string with delimeter.
         * @param arr: Vector of string.
         * @param delimiter: By which two strings are joined. (By default "")
         * @param swd: start with delimeter if it is true concatination starts with
         * delimeter, else start with given vactor's element (By default 'true')
         * @return usa::string& : Return a refrence of Concatenated string.
        ************************************************************************/
        __MYSTRING_REF__ join(std::vector<string> arr, string delimiter = "", __BOOL__ swd = true);
        /************************************************************************/


        /***********************************************************************
         * @name join
         * @overload +6
         * @brief Concatenate vector of std::string with orignal string with delimeter.
         * @param arr: Vector of std::string.
         * @param delimiter: By which two strings are joined. (By default "")
         * @param swd: start with delimeter if it is true concatination starts with
         * delimeter, else start with given vactor's element (By default 'true')
         * @return usa::string& : Return a refrence of Concatenated string.
        ************************************************************************/
        __MYSTRING_REF__ join(std::vector<__STDSTRING__> arr, string delimiter = "", __BOOL__ swd = true);
        /************************************************************************/


        /***********************************************************************
         * @name join
         * @overload +6
         * @brief Concatenate initializer list of string with orignal string with delimeter.
         * @param arr: Initializer list of string.
         * @param delimiter: By which two strings are joined. (By default "")
         * @param swd: start with delimeter if it is true concatination starts with
         * delimeter, else start with given initializer_list's element (By default 'true')
         * @return usa::string& : Return a refrence of Concatenated string.
        ************************************************************************/
        __MYSTRING_REF__ join(std::initializer_list<string> arr, string delimiter = "", __BOOL__ swd = true);
        /************************************************************************/


        /***********************************************************************
         * @name slice
         * @brief Advance extended String slicing. Approximately equal to String slicing in python.
         * 
         * @param _start: from where start the slicing of string (It might be negative).
         * @param _end: from where slicing ends (It might be negative).
         * @param _step: how many characters skiped during slicing (It might be negative).
         * @return usa::string& : Return a refrence of sliced string.
        ************************************************************************/
        __MYSTRING_REF__ slice(__INT__ _start = 0, __INT__ _end = 0, __INT__ _step = 0);
        /************************************************************************/


        /***********************************************************************
         * @name split
         * @brief Return a vector of the words in the string, using the delimiter to split the string.
         * The default value of delimiter (" ") means split according to any whitespace.
         * 
         * @param delimiter: By which function split the given string (By default " ").
         * @return vector std::string : Return a vector of splited tokens of string.
        ************************************************************************/
        vector<__STDSTRING__> split(const char* delimiter = " ");
        /************************************************************************/


        /***********************************************************************
         * @name splitlines
         * @brief use the split function with (delimiter = "\\n") so it splits the
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
        usa::string operator""x(const char* str, size_t size)
        {
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
        std::string operator""x(const char* str, size_t size)
        {
            return std::string(str);
        }

    #endif

#endif


#include "Resources/reststoi.tcc"

#endif // __cplusplus

#endif // __str_H__