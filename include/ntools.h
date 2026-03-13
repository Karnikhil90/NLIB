#ifndef NTOOLS_H
#define NTOOLS_H

#define not !=
#define is ==
#define and &&
#define or ||
#define ifnot(cond) if(!(cond))

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

enum buffer { 
    base_buffer = 1024,
    small_base_buffer = 128,
    
    buffer_4x = (base_buffer * 4), 
    buffer_8x = (base_buffer * 8), 
    buffer_16x = (base_buffer * 16), 
    buffer_24x = (base_buffer * 24),

    small_buffer_2x = (small_base_buffer * 2),
    small_buffer_4x = (small_base_buffer * 4),
    small_buffer_6x = (small_base_buffer * 6)
};

/*
    Types 
*/
typedef char *cstring; // char-array as string

typedef enum {
    False = 0,
    True  = 1
} Bool;


inline static const char* toBoolStr(Bool value){
    return value ? "True" : "False";
}

#endif