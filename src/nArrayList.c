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
    // For better calculation
    list.min_value = 0x7fffffff;
    list.max_value = INT_MIN; 
    return list;
}

ArrayList new_arr_copy(ArrayList arrary_list) {
    ArrayList list;  // Declare the list

    if (!arr_is_init(&arrary_list)) {
        perror("[ERROR] -> Not initialized");
        list.len = 0; // Set to an empty state
        return list;  // Return an empty ArrayList
    }

    // Initialize list with proper capacity and growth factor
    list = new_array_capacity(arrary_list.capacity, arrary_list.growth_factor);
    if (!list.n) {
        perror("[ERROR] -> Memory allocation failed");
        list.len = 0; // Set to an empty state
        return list;  // Return an empty ArrayList on failure
    }

    for (uint i = 0; i < arrary_list.len; i++) {
        arr_add(&list, arrary_list.n[i]);
    }
    
    list.len = arrary_list.len; // Ensure the length is set
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


ArrayList new_range(int start, int end, int update) {
    ArrayList list = {0};

    if (start < INT_MIN || start > INT_MAX) {
        perror("[ERROR] -> Start value is out of range");
        return list; 
    }

    if (end < INT_MIN || end > INT_MAX) {
        perror("[ERROR] -> End value is out of range");
        return list; 
    }

    if (update == 0) {
        perror("[ERROR] -> Update can't be zero");
        return list;
    }

    printf("[DEBUG] Initial values: \n");
    arr_print_extra(list);
    printf("\n");

    // Calculate the correct size
    int count = (abs(end - start) / abs(update)) + 1; // Using absolute value to account for negative updates
    list = new_array_capacity(count, _STD_FACTOR_GROWTH_);

    // Loop to add values
    for (int i = start; (start < end) ? (i <= end) : (i >= end); i += update) {
        arr_addF(&list, i);
        list.sum_value += i;

        // Update min and max
        if (i < list.min_value) {
            list.min_value = i;
        }
        if (i > list.max_value) {
            list.max_value = i;
        }
    }

    list.avg_value = list.len ? (list.sum_value / list.len) : 0;
    printf("[DEBUG] Final values: \n");
    arr_print_extra(list);
    printf("\n");
    
    return list;
}

ArrayList new_range_to(int start, int end){
    return new_range(start,end,1);
}
ArrayList new_range_(int end){
    return new_range(0,end,1);
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
//    printf("[DEBUG] Added value: %d at index %u\n", value, list->len-1);

   /*
       TODO: calculate(&list,value ,OPS_Add) -> Auxiliary Data set up
   */

   calculate(list, value, OPS_Add);
}



void arr_addF(ArrayList *list, int value) {
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
}

void arr_add_last(ArrayList arrary_list, int value){
    arr_add(&arrary_list, value);
}

void arr_add_first(ArrayList *arrary_list, int value) {
    if (arrary_list->len >= arrary_list->capacity) {
        new_resize(arrary_list);
    }
    arrary_list->len++;
    // Shifting 
    for (uint i = arrary_list->len; i > 0; i--) {
        arrary_list->n[i] = arrary_list->n[i - 1];
    }
    // arr_print(*arrary_list);
    arrary_list->n[0] = value;
}

/* END - CURD */

/* START - CALCULATE FUNCTION*/

void calculate(ArrayList *list, int value ,AuxiliaryDataOperation operations){
    switch (operations)
    {
    case OPS_Add :
        
        if(value is 0) list->zero_count++;
        else if(value > 0) list->positive_count++;
        else list->negative_count++;
        
        list->sum_value += value;
        list->avg_value = (list->sum_value / list->len);

        list->max_value = (list->max_value < value) ? value : list->max_value;
        list->min_value = (list->min_value > value) ? value : list->min_value;

        break;
    
    default:
        printf("[SW-DF] OPERATION NOT DEFINED");
        break;
    }
}

void calculate_clean(ArrayList *list){
    list->avg_value = 0;
    list->sum_value = 0;
    list->min_value = INT_MAX;
    list->max_value = INT_MIN; 

    list->len = 0;

    list->zero_count = 0;
    list->positive_count = 0;
    list->negative_count = 0;


}

/* END - CALCULATE FUNCTION*/


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


