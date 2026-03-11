// #include "nlib.h"
#include <stdio.h> 
#include "ntype.h"
// #include "nstring.h"
/*
    Example: String struct
*/

int main(){

    String a = new_string();
    String b = new_string();
    sappend(&a,  "Hello");
    sappend(&b,  "Hello");
    print(a);
    print(b);

    Bool isequal = isequals(a,b);
    printf("IS EQUALS = %s \n",toBoolStr(isequal)); // True
    return 0;
}

