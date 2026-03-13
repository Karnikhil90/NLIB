#include "nArrayList.h"

/* START - CONSTRUCTORS */

ArrayList new_array_capacity(uint arr_capacity, float growth) {
    ArrayList list = {0}; // Initialize struct to zeros

    if (arr_capacity <= 0) {
        perror("[TERMINATED] -> illegal value of a capacity");
        return list;
    }
    
    if (growth < 1.0f) {
        perror("[TERMINATED] -> illegal value of a growth Factor");
        return list;
    }

    list.capacity = arr_capacity;
    list.growth_factor = growth;
    list.n = (int *)malloc(list.capacity * sizeof(int)); 
    if (!list.n) {
        perror("malloc failed");
        exit(1);
    }

    list.len = 0; 
    return list;
}

ArrayList new_init(){
    return new_array_capacity(small_base_buffer, _STD_FACTOR_GROWTH_);
}

Bool new_resize(ArrayList *list) {
    printf("[DEBUG] -> REALLOC HAVE BEEN USED\n");
    
    if (list->capacity is 0) {
        *list = new_init();
        return True; 
    }
    
    if (list->capacity is 1 and list->growth_factor < 2.00f) {
        printf("[DEBUG] -> Bug fix capacity '1' with a less than 2 Growth FACTOR\n");
        list->capacity = 2; 
    }

    list->capacity *= list->growth_factor;
    int *new_array = realloc(list->n, list->capacity * sizeof(int));

    if (new_array == NULL) 
        return False;

    list->n = new_array;
    return True;
}

/* END - CONSTRUCTORS */

/*
    START - ERROR CHEAKING
*/

Bool arr_is_init(ArrayList *list){
    return (list->n != NULL and list->capacity > 0) ? True : False;
}

/*
    END - ERROR CHEAKING
*/



/* START - CURD */
// void arr_addAt(ArrayList arrary_list,int index ,int value)

void arr_add(ArrayList *list, int value) {
    Bool error_check = arr_is_init(list);
  
    if (!error_check) {
        perror("[ERROR] -> Not initialized");
        return;
    }

    if (list->len >= list->capacity) {
        printf("[ERROR] -> Cannot add more elements, capacity reached (%u).\n", list->capacity);
        return;
    }
    
    list->n[list->len] = value; 
    list->len++;
    
    if (list->len == list->capacity) {
        new_resize(list);
    }
   printf("[DEBUG] Added value: %d at index %u\n", value, list->len-1);

   /*
       TODO: calculate(&list,value ,OPS_Add) -> Auxiliary Data set up
   */
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
        printf("%d",arrary_list.n[i]);
        if(i < n - 1) {
            printf(", ");
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


