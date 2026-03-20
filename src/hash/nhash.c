#include "hash/nhash.h"

u32 hash_mod(u32 capacity, u32 value){
    return capacity ? (value % capacity) : 0;
}