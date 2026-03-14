#include <stdio.h> 
#include "nArrayList.h"

void make_line(){
    printf("\n=====================================================================\n\n");
}

int main(void){
    make_line();
    // ArrayList list = new_init();
    // arr_print(list);

    // for(int i = 1; i <= 5; i++) arr_add(&list, i);
    // arr_print(list);
    // arr_print_extra(list);
    // make_line();
    // ArrayList new_list = new_arr_copy(list);
    // arr_add(&new_list, 99);
    // arr_add(&new_list, 108);
    // arr_add(&new_list, 344);
    // arr_add(&new_list, -100);
    // arr_add(&new_list, 0);
    // arr_add(&new_list, 0);
    // arr_add(&new_list, 0);
    // arr_add(&new_list, -13);
    // arr_add_first(&new_list, 1000);

    // arr_print(new_list);
    // arr_print_extra(new_list);
    
    
    ArrayList list = new_range(0, 10, 1);
    arr_print(list);
    arr_print_extra(list);
    

    // for(int i = 10, i )


    make_line();


    return 0;
}