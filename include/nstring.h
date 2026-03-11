#ifndef NSTRING_H
#define NSTRING_H
/*
    Here String libs mean char array or char pointer.
    More like a string.h copy or python's versions of string functions as name

*/

#include "ntype.h"

#define BUFFER_UNIT 1024
#define MAX_BUFFER (BUFFER_UNIT * 8)

typedef char* str;

int len(char*);

int count(char* , char);

// string function
Bool lwr(char*);
Bool upr(char*);
void toLwr(char*);
void toUpr(char*);
void copy(char* new, char* old);
void repeate(char* , char);

substr(const char*, int end);
substr_range(const char*,int from, int end);



#endif 


