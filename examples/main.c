// #include "nlib.h"
#include <stdio.h> 
#include "ntype.h"
#include "nstring.h"
/*
    Example: String struct
*/

int main(){
    String hello = new_string();
    // String name = str("Nikhil Dada");
    strapp(&hello, "Hello, world! FROM NLIB");
    print(hello);
    // print(name);
    str_free(&hello);
    return 0;
}

