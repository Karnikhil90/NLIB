#include "ntype.h"
#include <stdio.h>
#include <stdlib.h>

void print(const String str){
    printf("[len=%d, capacity=%d] = '%s' \n", str.len, str.capacity, str.s);
}

String new_str(int size){
    String data;

    data.capacity = size;
    data.len = 0;

    data.s = (char*)malloc(data.capacity);

    if(!data.s){
        perror("malloc failed");
        exit(1);
    }

    data.s[0] = '\0';

    return data;
}

String new_string(){
    return new_str(base_buffer);
}

void str_append(String* s, char c){
    
    if(s->len + 1 >= s->capacity) {
        s->capacity = (s->capacity == 0) ? 4 : s->capacity * 1.5;
        printf("[realloc] CAP=%d \n",s->capacity);
        s->s = realloc(s->s, s->capacity);
        
        // return;
    
    }
    s->s[s->len++] = c;
    s->s[s->len] = '\0';
}
void strapp(String* str, const char* val){
    while(*val) str_append(str, *val++);
}
// String str(const char* cstr){
//     int size = 
// }


void str_free(String *root){
    free(root->s);
    root->s = NULL;
    root->len = 0;
    root->capacity = 0;
}