#ifndef NSTRING_H
#define NSTRING_H
/*
    Here String libs mean char array or char pointer.
    More like a string.h copy or python's versions of string functions
*/

#include "ntype.h"

#define BUFFER_UNIT 1024
#define MAX_BUFFER (BUFFER_UNIT * 8)

/* basic utilities */
int len(const char*);
int count(const char*, char);

/* string functions */
Bool lwr(const char*);
Bool upr(const char*);
void toLwr(char*);
void toUpr(char*);
void copy(char* new, const char* old);
void repeat(char*, char);

/* substring utilities */
char* substr(const char*, int end);
char* substr_range(const char*, int from, int end);

#endif