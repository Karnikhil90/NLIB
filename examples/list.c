#include <stdio.h> 
#include "nArrayList.h"

int main(void){
    printf("\n=====================================================================\n\n");

    ArrayList list = new_init();
    arr_print(list);
    arr_print_extra(list);
    
    return 0;
}