#ifndef NTYPE_H
#define NTYPE_H

#include <stddef.h>

#define is ==
#define not !=

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


/* CONSTRUCTORS */
String new_string();
String new_str(int size);
String cstr(const char* cstr);
void str_free(String *root);


/* UTILITY */
void print(String str);
Bool str_equal(String a, String b);
String str_copy(String s);
char str_idx(String s, int idx);
void str_append(String* s, char c);
void strapp(String* s, const char* txt);

#endif