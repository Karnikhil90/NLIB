#ifndef NTYPE_H
#define NTYPE_H

#include <stddef.h>

#define is ==
#define not !=
#define and &&

#define BUFFER_UNIT 1024

enum buffer {
    base_buffer = 1024,
    buffer_4x = (base_buffer * 4),
    buffer_8x = (base_buffer * 8),
    buffer_16x = (base_buffer * 16),
    buffer_24x = (base_buffer * 24)
};

typedef enum {
    False = 0,
    True = 1
} Bool;

typedef struct String {
    int capacity;
    int len;
    char* s;
} String;

/*
 utility
*/

static inline char* toBoolStr(const Bool val){
    return val ? "True" : "False";
}

int len(const char*);
void str_cpy(char *to ,const char *from);

/* CONSTRUCTORS */
String new_string();
String new_str(int size);
String cstr(const char* cstr);
void str_free(String *root);


/* UTILITY for String struct */
void print(String str);
Bool isequals(String a, String b);
String str_copy(String s);
char str_idx(String s, int idx);
void str_append(String* s, char c);
void sappend(String* s, const char* txt);

#endif