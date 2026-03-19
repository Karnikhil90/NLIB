#include "hash/nhash.h"


u32 hash_mod(u32 capactiy, u32 value){
    return capacity ? (value % capacity) : 0;
}