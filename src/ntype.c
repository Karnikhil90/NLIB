#include "ntype.h"

void print(const String str){
    printf("[len=%d, capacity=%d] = '%s' \n", str.len, str.capacity, str.s);
}

String str_with_capacity(int size){
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

String str_new(){
    return str_with_capacity(base_buffer);
}

void str_append_char(String* s, char c){
    
    if(s->len + 1 >= s->capacity) {
        s->capacity = (s->capacity == 0) ? 4 : s->capacity * 1.5;
        s->s = realloc(s->s, s->capacity);
    }

    s->s[s->len++] = c;
    s->s[s->len] = '\0';
}

void str_append_cstr(String* str, const char* val){
    while(*val) str_append_char(str, *val++);
}

String str_default(const char* value){
    int n = len(value);
    String output = str_with_capacity(
        (n) ? n + 1 : 0
    );
    str_append_cstr(&output, value);
    return output;
}

void str_clear(String *s){
    s->len = 0;
    s->s[0] = '\0';
}

// String str_substr_f(String s, int start, int end){

// }
#include <stdio.h>

void str_set(String *string, int index, char c) {
    if (string->len == 0) {
        printf("Error: string is empty!\n");
        return;
    }

    if (index < 0) {
        index = string->len + index; // Negative index 
    }

    if (index < 0 || index >= string->len) {
        printf("Error: index %d out of range [0, %d)\n", index, string->len);
        return;
    }

    string->s[index] = c;
}


int str_find_char(String value, char key){
    if(value.len is 0) return -1;
    for(int i = 0; i < value.len; i++) {
        if(value.s[i] == key)
            return i;
    }
    return -1;
}



String str_from(const char* c){
    int size = len(c);
    // printf("DEBUG [size=%d] \n", size);

    String output = str_with_capacity(
        (size) ? size + 1 : 0
    );

    str_cpy(output.s, c);
    output.len = size;

    return output;
}

char str_at(String s, int idx){
    if(s.len < idx || s.len is 0) return ' ';
    return (idx > 0) ? s.s[idx] : s.s[s.len + idx];
}

Bool str_empty(String string){
    if(string.capacity is 0 || string.len is 0) return True;
    return False;
}

Bool str_equal(String a, String b){
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