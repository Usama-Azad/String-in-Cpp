///                           -*- @c C/C++ headers -*-

///                  -*- @c #include"usastringfunctool.h" -*-


/**
 * @author Usama Azad @c <https://github.com/Usama-Azad>
 * 
 * @dependencies: [ <vector> , <string> , <sstream> , <algorithm> , <initializer_list> ]
 * 
 * This @c header is distributed in the hope that it will be useful,
 * but @a WITHOUT_ANY_WARRANTY; without even the implied @c warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
**/


//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.




#ifndef __StrFunc_H__
#define __StrFunc_H__

#ifdef __cplusplus

#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <initializer_list>
using namespace std;


/// @e convet_to_string.


/***********************************************************************
 * @name ItoS
 * @param val: Any integer.
 * @return string: After converting given integer to string.
************************************************************************/
inline
string ItoS(const int &val);
/************************************************************************/


/***********************************************************************
 * @name CtoS
 * @param val: Any character.
 * @return string: After converting given character to string.
************************************************************************/
inline
string CtoS(const char &val);
/************************************************************************/


/***********************************************************************
 * @name FtoS
 * @param val: Any float.
 * @return string: After converting given float to string.
************************************************************************/
inline
string FtoS(const float &val);
/************************************************************************/


/***********************************************************************
 * @name DtoS
 * @param val: Any double.
 * @return string: After converting given double to string.
************************************************************************/
inline
string DtoS(const double &val);
/************************************************************************/


/***********************************************************************
 * @name LtoS
 * @param val: Any long.
 * @return string: After converting given long to string.
************************************************************************/
inline
string LtoS(const long &val);
/************************************************************************/


/***********************************************************************
 * @name LDtoS
 * @param val: Any long double.
 * @return string: After converting given long double to string.
************************************************************************/
inline
string LDtoS(const long double &val);
/************************************************************************/


/***********************************************************************
 * @name BtoS
 * @param val: Any bool.
 * @return string: After converting given bool to string.
************************************************************************/
inline
string BtoS(const bool &val);
/************************************************************************/


/// @a Convesions_Ends.




/// @e convet_from_string.


/***********************************************************************
 * @name StoI
 * @param str: Any string.
 * @return int: After converting given string to int.
************************************************************************/
inline
int StoI(const string &str);
/************************************************************************/


/***********************************************************************
 * @name StoC
 * @param str: Any string.
 * @return char: After converting given string to char.
************************************************************************/
inline
char StoC(const string &str);
/************************************************************************/


/***********************************************************************
 * @name StoF
 * @param str: Any string.
 * @return float: After converting given string to float.
************************************************************************/
inline
float StoF(const string &str);
/************************************************************************/


/***********************************************************************
 * @name StoD
 * @param str: Any string.
 * @return double: After converting given string to double.
************************************************************************/
inline
double StoD(const string &str);
/************************************************************************/


/***********************************************************************
 * @name StoL
 * @param str: Any string.
 * @return long: After converting given string to long.
************************************************************************/
inline
long StoL(const string &str);
/************************************************************************/


/***********************************************************************
 * @name StoLD
 * @param str: Any string.
 * @return long double: After converting given string to long double.
************************************************************************/
inline
long double StoLD(const string &str);
/************************************************************************/


/***********************************************************************
 * @name StoB
 * @param str: Any string.
 * @return bool: After converting given string to bool.
************************************************************************/
inline
bool StoB(const string &str);
/************************************************************************/


/// @a Convesions_Ends.


#if __cplusplus >= 201402L
#define exchangeX std::exchange
#else
template<class X, class Y = X>
X _exchangeX(X& first, const Y& second)
{
    X oldV = first;
    first = second;
    return oldV;
}
#define exchangeX _exchangeX
#endif


/***********************************************************************
 * @name split
 * @param str: const string refrence which is to be splited.
 * @param delimiter: delimiter by which string is splited.
 * @return vector<string>: vector of different chunks of splited string.
************************************************************************/
vector<string> split(const string& str, const char& delimiter = 0x020);
/************************************************************************/



#if __cplusplus >= 201102L


/***********************************************************************
 * @name trim
 * @param str: const string refrence which is to be trimed.
 * @return string: Return a copy of the string with leading and trailing
 * whitespace remove.
 * 
 * @ltrim: it only trims only left spaces.
 * @rtrim: it only trims only right spaces.
 * @trim: it trims spaces from both sides.
 * @strip: it works like trim() but it does not return any thing.
************************************************************************/
string ltrim(const string& str);

string rtrim(const string& str);

string _trim(const string& str);

void strip(string& s);

/************************************************************************/


#endif


/***********************************************************************
 * @name reverse
 * @param str: string and reverse it.
 * @return string: reversed string.
************************************************************************/
string reverse(string str);
/************************************************************************/


/***********************************************************************
 * @name replace
 * @param str: string.
 * @param prev: old char which is present in given string.
 * @param next: new char which is to be replaced with old char in given string.
 * @return string: new string with replaced all characters.
************************************************************************/
string replace(string str, char prev, char next);
/************************************************************************/


/***********************************************************************
 * @name replace_first
 * @param str: string.
 * @param prev: old char which is present in given string.
 * @param next: new char which is to be replaced with old char in given string.
 * @return string: new string with only first replaced characters.
************************************************************************/
string replace_first(string str, char prev, char next);
/************************************************************************/


/***********************************************************************
 * @name is_Upper
 * @param str: string.
 * @return bool: true if all chars in string is upperCase else false.
************************************************************************/
bool is_Upper(const string& str);
/************************************************************************/


/***********************************************************************
 * @name is_Lower
 * @param str: string.
 * @return bool: true if all chars in string is lowerCase else false.
************************************************************************/
bool is_Lower(const string& str);
/************************************************************************/


/***********************************************************************
 * @name to_UpperCase
 * @param str: string.
 * @return string: string with all chars in UpperCase.
************************************************************************/
string to_UpperCase(string str);
/************************************************************************/


/***********************************************************************
 * @name to_LowerCase
 * @param str: string.
 * @return string: string with all chars in LowerCase.
************************************************************************/
string to_LowerCase(string str);
/************************************************************************/


#endif
#endif