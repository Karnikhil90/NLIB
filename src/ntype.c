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
        // printf("[realloc] CAP=%d \n",s->capacity);
        s->s = realloc(s->s, s->capacity);
        
        // return;
    
    }
    s->s[s->len++] = c;
    s->s[s->len] = '\0';
}

void sappend(String* str, const char* val){
    while(*val) str_append(str, *val++);
}

String cstr(const char* c){
    int size = len(c);
    printf("DEBUG [size=%d] \n", size);

    String output = new_str(
        (size) ? size + 1 : 0
    );

    str_cpy(output.s, c);
    output.len = size;
    // str_free(&output);
    return output;
}


Bool isequals(String a, String b){
    if(a.len not b.len) return False;
    if(a.len is 0) return True;

    int idx = 0;
    while(idx < a.len){
        if(a.s[idx] not b.s[idx]) return False;
        idx++;
    }
    return True;
}

int len(const char* string){
    int size = 0;
    while(*string++ && (buffer_16x >= size)) size++;
    return size;
}

void str_cpy(char *to , const char *from){
    while((*to++ = *from++));
    *to = '\0';
}

void str_free(String *root){
    free(root->s);
    root->s = NULL;
    root->len = 0;
    root->capacity = 0;
}