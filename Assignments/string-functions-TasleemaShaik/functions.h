#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>

///
/// @brief      { Return the length of the given null-terminated string, up to
///             and not including the first null character }
///
/// @note       { If str is a null pointer, return 0. If str points to an empty
///             string, return 0. The behavior is undefined if str is not a
///             pointer to a null-terminated byte string. }
///
/// @param[in]  str   pointer to the null-terminated byte string to be examined
///
/// @return     { the length of the null-terminated byte string str }
///
size_t mystrlen(const char* str);

///
/// @brief      { Compare two null-terminated strings lexicographically }
///
/// @param[in]  lhs   pointer to the left null-terminated byte string to compare
/// @param[in]  rhs   pointer to the right null-terminated byte strings to compare
///
/// @return     { -1 if lhs appears before rhs in lexicographic order
/// 			   0 if lhs and rhs are the same string
/// 			   1 if lhs appears after rhs in lexicographic order }
///
int mystrcmp(const char *lhs, const char *rhs);

///
/// @brief      { Finds the first occurrence of the null-terminated byte string
///             pointed to by substr in the null-terminated byte string pointed
///             to by str.}
/// @note       {The terminating null characters are not compared. }
///
/// @param[in]  str     pointer to the null-terminated byte string to examine
/// @param[in]  substr  pointer to the null-terminated byte string to search for
///
/// @return     { Pointer to the first character of the found substring in str,
///             or a null pointer if such substring is not found. If substr
///             points to an empty string, str is returned. }
///
char *mystrstr(const char* str, const char* substr);

///
/// @brief      { Removes leading and trailing whitespace from a string. }
/// @note       { Requests a heap allocation of the minimum size to contain the
///             original string with leading and trailing whitespace removed.
///             The original string is unmodified. It is the caller's
///             responsibility to check for a returned null pointer and to free
///             the returned string. }
///
/// @param[in]  str   Pointer to the string
///
/// @return     { Pointer to a new string, which is stripped of leading and
///             trailing whitespace. If @p str is null, a null pointer is
///             returned and no memory is allocated.  }
///
char *mystrstrip(const char* str);

///
/// @brief      { Apply a predicate function to elements of an array
///             collectively }
///
/// @param[in]  ptr    Pointer to the array of elements
/// @param[in]  nmemb  The number of elements in the array
/// @param[in]  size   The size of each element in bytes
/// @param[in]  pred   Predicate function to apply to each member in the array
///
/// @return     { Returns true if the predicates of all elements are true,
///             returns false otherwise. If ptr is null, return false. }
///
bool all(const void *ptr, size_t nmemb, size_t size,
         bool (*pred)(const void *));

///
/// @brief      { Apply a predicate function to elements of an array
///             individually }
///
/// @param[in]  ptr    Pointer to the array of elements
/// @param[in]  nmemb  The number of elements in the array
/// @param[in]  size   The size of each element in bytes
/// @param[in]  pred   Predicate function to apply to each member in the array
///
/// @return     { Returns true if the predicate of any element is true, returns
///             false otherwise. If ptr is null, return false. }
///
bool any(const void *ptr, size_t nmemb, size_t size,
         bool (*pred)(const void *));

///
/// @defgroup   wrappers (ctype.h wrappers)
/// @note       { These functions convert the ctype.h character classification
///             functions prototypes from int pred(int) to bool
///             mypred(const void *) in order to allow their use as
///             callback functions for any() and all(). You may include ctype.h
///             and call the matching predicate function after casting the 
///             arguments }
///

///
/// @brief      { checks if the given characer is alphanumeric }
/// @ingroup    wrappers
///
/// @param[in]  ptr   pointer to a character
///
/// @return     { returns true only for the digits, uppercase letters, and
///             lowercase letters }
///
bool myisalnum(const void *ptr);

///
/// @brief      { Checks if the given character is an alphabetic character }
///
/// @param[in]  ptr   pointer to a character
///
/// @return     { returns true only for uppercase or lowercase letters }
///
bool myisalpha(const void *ptr);

///
/// @brief      { Checks if the given character is a control character }
/// @ingroup    wrappers
///
/// @param[in]  ptr   pointer to a character
///
/// @return     { returns true only for the control characters [0x00-0x1f|0x7f] }
///
bool myiscntrl(const void *ptr);


///
/// @brief      { Checks if the given character is a numeric character }
/// @ingroup    wrappers
///
/// @param[in]  ptr   pointer to a character
///
/// @return     { returns true only for the numeric characters [0-9] }
///
bool myisdigit(const void *ptr);

///
/// @brief      { Checks if the given character is classified as a lowercase
///             character  }
/// @ingroup    wrappers
///
/// @param[in]  ptr   pointer to a character
///
/// @return     { return true only for the lowercase letters [a-z]  }
///
bool myislower(const void *ptr);

///
/// @brief      { checks if the given character can be printed }
/// @ingroup    wrappers
///
/// @param[in]  ptr   pointer to a character
///
/// @return     { returns true only for the digits, uppercase letters, lowercase
///             letters, punctuation, and the space character }
///
bool myisprint(const void *ptr);

///
/// @brief      { Checks if the given character is a punctuation character }
/// @ingroup    wrappers
///
/// @param[in]  ptr   pointer to a character
///
/// @return     { returns true only for the punctuation characters
///             [!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~] }
///
bool myispunct(const void *ptr);

///
/// @brief      { Checks if the given character is a standard whitespace
///             character }
/// @ingroup    wrappers
///
/// @param[in]  ptr   pointer to a character
///
/// @return     { returns true only for the whitespace characters
///             [0x09-0x0d|0x20] }
///
bool myisspace(const void *ptr);

///
/// @brief      { Checks if the given character is an uppercase character }
/// @ingroup    wrappers
///
/// @param[in]  ptr   pointer to a character
///
/// @return     { returns true only for the uppercase letters [A-Z] }
///
bool myisupper(const void *ptr);

///
/// @brief      { Checks if the given character is a hexadecimal numeric
///             character }
/// @ingroup    wrappers
///
/// @param[in]  ptr   pointer to a character
///
/// @return     { returns true only for the hexadecimal numeric characters
///             [0-9|a-f|A-F] }
///
bool myisxdigit(const void *ptr);

#endif //FUNCTIONS_H