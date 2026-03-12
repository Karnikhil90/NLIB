#ifndef STRING_LIB_H
#define STRING_LIB_H

#include <stddef.h>

#define not !=
#define is ==
#define and &&
#define or ||
#define ifnot(cond) if(!(cond))

enum buffer { base_buffer = 1024, 
    buffer_4x = (base_buffer * 4), 
    buffer_8x = (base_buffer * 8), 
    buffer_16x = (base_buffer * 16), 
    buffer_24x = (base_buffer * 24) 
};

/*
    Types 
*/
typedef enum {
    False = 0,
    True  = 1
} Bool;

typedef struct {
    int capacity;
    int len;
    char *s;
} String;


/* CONSTRUCTORS */

String str_new(); // 1024 size as default
String str_with_capacity(int capacity);
String str_default(const char* value); // create just by giving value
String str_from(const char *cstr); // from C string
String str_copy(String s); // deep copy
void   str_free(String *s);


/*
   BASIC INFO 
*/

int len(const char* string);
int str_capacity(String s);
Bool str_empty(String s);
/* works like python index system... negative value also works*/
char str_at(String s, int i); 


/* APPEND / MODIFY */

void str_append_char(String *s, char c);
void str_append_cstr(String *s, const char *txt);
void str_append_str(String *s, String other);
void str_cpy(char *to , const char *from);
void str_clear(String *s);// clear content
// void str_reserve(String *s, int size);// ensure capacity


/* COMPARISON */

Bool str_equal(String a, String b);
int  str_compare(String a, String b);


/* SEARCH */

int  str_find_char(String s, char c);
int  str_find_str(String s, const char *txt);
Bool str_contains(String s, const char *txt);


/* SUBSTRING */

String str_substr_f(String s, int start, int end);
String str_substr(String s, int start);




/* EDITING */

void str_set(String *string, int index, char c);
void str_insert(String *string, int index, char c);
void str_remove(String *string, int index);


/* UTILITY */

void print(String s);

#endif