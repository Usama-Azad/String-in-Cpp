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
string __cdecl ItoS(int val);
/************************************************************************/


/***********************************************************************
 * @name CtoS
 * @param val: Any character.
 * @return string: After converting given character to string.
************************************************************************/
inline
string __cdecl CtoS(char val);
/************************************************************************/


/***********************************************************************
 * @name FtoS
 * @param val: Any float.
 * @return string: After converting given float to string.
************************************************************************/
inline
string __cdecl FtoS(float val);
/************************************************************************/


/***********************************************************************
 * @name DtoS
 * @param val: Any double.
 * @return string: After converting given double to string.
************************************************************************/
inline
string __cdecl DtoS(double val);
/************************************************************************/


/***********************************************************************
 * @name LtoS
 * @param val: Any long.
 * @return string: After converting given long to string.
************************************************************************/
inline
string __cdecl LtoS(long val);
/************************************************************************/


/***********************************************************************
 * @name LDtoS
 * @param val: Any long double.
 * @return string: After converting given long double to string.
************************************************************************/
inline
string __cdecl LDtoS(long double val);
/************************************************************************/


/***********************************************************************
 * @name BtoS
 * @param val: Any bool.
 * @return string: After converting given bool to string.
************************************************************************/
inline
string __cdecl BtoS(bool val);
/************************************************************************/


/// @a Convesions_Ends.




/// @e convet_from_string.


/***********************************************************************
 * @name StoI
 * @param str: Any string.
 * @return int: After converting given string to int.
************************************************************************/
inline
int __cdecl StoI(string str);
/************************************************************************/


/***********************************************************************
 * @name StoC
 * @param str: Any string.
 * @return char: After converting given string to char.
************************************************************************/
inline
char __cdecl StoC(string str);
/************************************************************************/


/***********************************************************************
 * @name StoF
 * @param str: Any string.
 * @return float: After converting given string to float.
************************************************************************/
inline
float __cdecl StoF(string str);
/************************************************************************/


/***********************************************************************
 * @name StoD
 * @param str: Any string.
 * @return double: After converting given string to double.
************************************************************************/
inline
double __cdecl StoD(string str);
/************************************************************************/


/***********************************************************************
 * @name StoL
 * @param str: Any string.
 * @return long: After converting given string to long.
************************************************************************/
inline
long __cdecl StoL(string str);
/************************************************************************/


/***********************************************************************
 * @name StoLD
 * @param str: Any string.
 * @return long double: After converting given string to long double.
************************************************************************/
inline
long double __cdecl StoLD(string str);
/************************************************************************/


/***********************************************************************
 * @name StoB
 * @param str: Any string.
 * @return bool: After converting given string to bool.
************************************************************************/
inline
bool __cdecl StoB(string str);
/************************************************************************/


/// @a Convesions_Ends.




/***********************************************************************
 * @name split
 * @param str: const string refrence which is to be splited.
 * @param delimiter: delimiter by which string is splited.
 * @return vector<string>: vector of different chunks of splited string.
************************************************************************/
vector<string> split(const string& str, const char* delimiter = " ");
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

string trim(const string& str);

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
bool is_Upper(string str);
/************************************************************************/


/***********************************************************************
 * @name is_Lower
 * @param str: string.
 * @return bool: true if all chars in string is lowerCase else false.
************************************************************************/
bool is_Lower(string str);
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