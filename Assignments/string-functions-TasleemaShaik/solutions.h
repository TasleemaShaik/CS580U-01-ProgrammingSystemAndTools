#ifndef SOLUTIONS_H
#define SOLUTIONS_H

#include <stdbool.h>
#include <stddef.h>

size_t _mystrlen(const char *str);
int _mystrcmp(const char *lhs, const char *rhs);
char *_mystrstr(const char *str, const char *substr);
char *_mystrstrip(const char *str);
bool _any(const void *ptr, size_t nmemb, size_t size,
          bool (*pred)(const void *));
bool _all(const void *ptr, size_t nmemb, size_t size,
          bool (*pred)(const void *));

bool _myisalnum(const void *ptr);
bool _myisalpha(const void *ptr);
bool _myiscntrl(const void *ptr);
bool _myisdigit(const void *ptr);
bool _myislower(const void *ptr);
bool _myisprint(const void *ptr);
bool _myispunct(const void *ptr);
bool _myisspace(const void *ptr);
bool _myisupper(const void *ptr);
bool _myisxdigit(const void *ptr);

#endif //SOLUTIONS_H
