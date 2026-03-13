#include "nArrayList.h"

/* START - CONSTRUCTORS */

ArrayList new_array_capacity(int arr_capacity, float growth){
    ArrayList list = {0}; // Set all the values to 'Zero'

    list.capacity = arr_capacity;
    list.growth_factor = growth;

    list.n = (int*)malloc(list.capacity);

    ifnot(list.n){
        perror("malloc failed");
        exit(1);
    }

    return list; 
}

ArrayList new_init(){
    return new_array_capacity(small_base_buffer, _STD_FACTOR_GROWTH_);
}

Bool new_resize(ArrayList *list){
    if(list->capacity is 0) {
        *list = new_init();
        return True;
    }
        
    list->capacity *= list->growth_factor;
    int *new_array = realloc(list->n, list->capacity * sizeof(int));

    if(*new_array is NULL) 
        return False;
    list->n = new_array;

    return True;
}

/* END - CONSTRUCTORS */



/* START - CURD */
// void arr_addAt(ArrayList arrary_list,int index ,int value)

void arr_add(ArrayList *list, int value) {
    
    



}

void arr_add_last(ArrayList arrary_list, int value){
    arr_add(&arrary_list, value);
}

/* END - CURD */


/* START - DISPLAY THE ARRAY */

void arr_print(ArrayList arrary_list){
    uint n = arrary_list.len;
    printf("[len=%u, cap=%u] ",n, arrary_list.capacity);

    printf(" {");
    for(uint i = 0; i < n;i++){
        ifnot(i == n - 1) {
            printf("%d, ",arrary_list.n[i]);
        }
    }
    printf("}\n");
    
}
void arr_print_extra(ArrayList list){
    printf("values -> [max=%d, min=%d, avg=%d, sum=%d ] \n" , list.max_value, list.min_value,list.avg_value,list.sum_value);
    printf("counts -> [posivite=%d, negative=%d, zero=%d ]\n" , list.positive_count, list.negative_count,list.zero_count);
    printf("basic  -> [capacity=%u, length=%u, growth=%.2f ]\n" ,list.capacity,list.len,list.growth_factor);
}

/* END - DISPLAY THE ARRAY */


