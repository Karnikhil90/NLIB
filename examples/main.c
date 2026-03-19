// #include "nlib.h"
#include <stdio.h> 
#include "ntype.h"
#include "hash/nhash.h"
// #include "nstring.h"
/*
    Example: String struct
*/

int main(){
    // String a = str_default("Im Nikhil ");
    // print(a);
    // str_append_cstr(&a , "And this is my libbbb"); // Increased the capacity by 1.5x
    // print(a);
    // str_set(&a , -30, 'Q');
    // print(a);
    // return 0;

    u32 value = 100;

    printf("value=%d, hash=%u", value , hash_mod(13, value));
}

