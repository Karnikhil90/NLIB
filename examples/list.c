#include <stdio.h> 
#include "nArrayList.h"

int main(void){
    printf("\n=====================================================================\n\n");

    ArrayList list = new_array_capacity(1,2);
    arr_print(list);

    for(int i = 1; i <= 5; i++) arr_add(&list, i);
    arr_print(list);
    arr_print_extra(list);
    
    return 0;
}