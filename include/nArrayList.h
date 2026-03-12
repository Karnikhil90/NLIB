#ifndef NARRAYLIST_H
#define NARRAYLIST_H
#include "ntools.h"

/*
TODO: 

1. calculate() -> will calculate all these max,min,avg & etc.
2. calculate_clean() -> it can reset to zero everything whcih is not imp
3.arr_merge() add 2 array list
arr_sublist


1. function as agrs
like => arr_for_each() and arr_filter()

example of the function
arr_filter(ArrayList arr, Bool (*predicate)(int))


Iterator can be cooked


*/

typedef struct ArrayList {
    int max_value;
    int min_value;
    int avg_value;
    int sum_value;
    int median_value;

    int positive_count; 
    int negative_count; 
    int zero_count;

    unsigned int capacity;
    unsigned int len;
    float growth_factor;
    int *n;

} ArrayList;


/* CONSTRUCTOR */
ArrayList new_array_capacity(int arr_capacity, float growth);
ArrayList new_init(); // default capacity is small_base_buffer
ArrayList new_arr_copy(ArrayList arrary_list); // Deep Copy
ArrayList new_range(int start, int end, int update);
ArrayList new_range_to(int start, int end);
ArrayList new_range_(int end);
ArrayList new_range_reverce(int start, int end, int update);


void arr_free(ArrayList *array_list);

void arr_add(ArrayList arrary_list, int value);
void arr_addAt(ArrayList arrary_list,int index ,int value);
void arr_add_last(ArrayList arrary_list, int value);
void arr_add_first(ArrayList arrary_list, int value);
void arr_clean(ArrayList *arrary_list);

int arr_get(ArrayList arrary_list, int index);
int arr_get_last(ArrayList arrary_list);
int arr_get_first(ArrayList arrary_list);

int arr_pop(ArrayList *arrary_list);
int arr_remove(ArrayList *arrary_list, int index);
int arr_remove_first(ArrayList *arrary_list);
int arr_remove_last(ArrayList *arrary_list);

int arr_remove_val(ArrayList *arrary_list, int value); // return index 
int arr_remove_all(ArrayList *arrary_list, int value); // return the len

// searching
int arr_contain(ArrayList *arrary_list, int key); // return index 
Bool arr_contain(ArrayList *arrary_list, int key);
Bool arr_in(ArrayList *arrary_list1, ArrayList *arrary_list2);

Bool arr_is_empty(ArrayList *arrary_list);

void arr_print(ArrayList arrary_list); 
void arr_print_revece(ArrayList arrary_list);
void arr_print_extra(ArrayList arrary_list); // will display except int* vals




#endif