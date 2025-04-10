#ifndef RANDSTR_H
#define RANDSTR_H

/**
 * @brief      { get a random string from a randomly selected wordlist }
 * @note       { The space for the random string is obtained as if malloc() was
 *             called. It is the caller's responsibility to check for a null
 *             pointer, and to pass the returned pointer to free() to avoid a
 *             memory leak. If an error occurs, a null pointer is returned and
 *             errno may be set. }
 *
 * @return     { a random string }
 */
char *randstr(void);

/**
 * @brief      { get a random substring from a string }
 * @note       { The space for the random substring is obtained as if malloc()
 *             was called. It is the caller's responsibility to check for a null
 *             pointer, and to pass the returned pointer to free() to avoid a
 *             memory leak. If an error occurs, a null pointer is returned and
 *             errno may be set. }
 *
 * @param      str   source string
 *
 * @return     { a random substring of @p str }
 */
char *randsubstr(char *str);

#endif //RANDSTR_H