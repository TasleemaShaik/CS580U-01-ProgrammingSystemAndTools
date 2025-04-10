#include "functions.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

size_t mystrlen(const char *str) {
       int strLenCount = 0;
       const char* t;
       for (t = str; *t != '\0'; t++) {
       		strLenCount++;
       }
       return strLenCount;
}

int mystrcmp(const char *lhs, const char *rhs) {
    while (*lhs != '\0' || *rhs != '\0') {
        if (*lhs == '\0' && *rhs != '\0') {
            return -1;
        } else if (*lhs != '\0' && *rhs == '\0') {
            return 1;
        } else if (*lhs < *rhs) {
            return -1;
        } else if (*lhs > *rhs) {
            return 1;
        }
        lhs++;
        rhs++;
    }
    return 0;
}

char *mystrstr(const char *str, const char *substr) {
    if (*substr == '\0')
        return (char*)str;
    while (*str != '\0') {
        const char* temp_str = str;
        const char* temp_substr = substr;
        while (*temp_str != '\0' && *temp_substr != '\0' && *temp_str == *temp_substr) {
            temp_str++;
            temp_substr++;
        }
        if (*temp_substr == '\0')
            return (char*)str;
        str++;
    }
    return NULL;	
}

char *mystrstrip(const char *str) { 
    if (str == NULL)
        return NULL;
    while (*str != '\0' && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r')) {
        str++;
    }
    const char* end = str;
    while (*end != '\0') {
        end++;
    }
    end--;
    while (end >= str && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\v' || *end == '\f' || *end == '\r')) {
        end--;
    }
    int stripped_len = (end - str) + 1;
    char* result = (char*)malloc((stripped_len + 1) * sizeof(char)); // +1 for null terminator
    if (result == NULL)
        return NULL;
    for (int i = 0; i < stripped_len; i++) {
        result[i] = *str;
        str++;
    }
    result[stripped_len] = '\0';
    return result;
}

bool any(const void *ptr, size_t nmemb, size_t size,
         bool (*pred)(const void *)) {
    const char *buffer = ptr;
    for (size_t i = 0; i < nmemb; ++i) {
        if (pred(buffer)) {
            return true;
        }
        buffer += size;
    }
    return false;
}

bool all(const void *ptr, size_t nmemb, size_t size,
         bool (*pred)(const void *)) {
    const char *buffer = ptr;
    for (size_t i = 0; i < nmemb; ++i) {
        if (!pred(buffer)) {
            return false;
        }
        buffer += size;
    }
    return true;
}

bool myisalnum(const void *ptr) { 
	return isalnum(*(const unsigned char *)ptr);
}

bool myisalpha(const void *ptr) { 
	return isalpha(*(const unsigned char *)ptr);
}

bool myislower(const void *ptr) { 
	return islower(*(const unsigned char *)ptr);
}

bool myisupper(const void *ptr) {
	return isupper(*(const unsigned char *)ptr);
}

bool myisdigit(const void *ptr) { 
	return isdigit(*(const unsigned char *)ptr);
}

bool myisxdigit(const void *ptr) {
	return isxdigit(*(const unsigned char *)ptr);
}

bool myiscntrl(const void *ptr) {
	return iscntrl(*(const unsigned char *)ptr);
}

bool myisspace(const void *ptr) {
	return isspace(*(const unsigned char *)ptr);
}

bool myispunct(const void *ptr) {
	return ispunct(*(const unsigned char *)ptr);
}

bool myisprint(const void *ptr) { 
	return isprint(*(const unsigned char *)ptr);
}
