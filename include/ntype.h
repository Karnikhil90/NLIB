#ifndef NTYPE_H
#define NTYPE_H
#define is ==
#define not !=

#include <stddef.h>  // for size_t

#define BUFFER_UNIT 1024

enum buffer {
    base_buffer = 1024,
    buffer_4x = base_buffer * 4,
    buffer_8x = base_buffer * 8,
    buffer_16x = base_buffer * 16,
    buffer_24x = base_buffer * 24
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


/* Basic String utility functions */

/* CONSTRUCTORS */
String new_string();           // malloc 1024 chars
String new_str(int size);      // malloc size
String str(const char* cstr);  // create String from c-string
void str_free(String *root);


/* UTILITY */
void print(String str);
Bool str_equal(String a, String b);
String str_copy(String s);
char str_idx(String s, int idx);        // works like Python indexing
void str_append(String* s, char c);    // append single char
void strapp(String* s, const char* txt); // append C-string




#endif