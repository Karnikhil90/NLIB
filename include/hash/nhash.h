#ifndef NHASH_H
#define NHASH_H

#include "../ntools.h"

/**
 * nhash.h
 * 
 * 
 * Will have hashing utilities for:
 *     - HashMap / HashSet implementations (non-cryptographic)
 *     - Optional cryptographic-style hash functions (separate section)
 * Design:
 *   - Lightweight, dependency-free
 *   - Suitable for embedded / low-level systems
 * 
 * Errors:
 *      - ERROR SAFTY ALSO WILL BE THERE
 *      - ERROR WILL BE VERY CLEAR WHERE IS THE PROBLEM
 */


typedef unsigned int u32;
typedef unsigned long long u64;


// Division Method
u32 hash_mod(u32 value, u32 capacity);

// Knuth's Multiplicative Method
u32 hash_knuth(u32 value);

// MurmurHash3 (32-bit)
u32 hash_murmur3_32(const void *key, int len, u32 seed);

// Fowler-Noll-Vo (FNV-1a)
u32 hash_fnv1a(const void *key, int len);

// Dan Bernstein's djb2
u32 hash_djb2(const char *str);

// SDBM Algorithm
u32 hash_sdbm(const char *str);

// Jenkins One-at-a-Time
u32 hash_jenkins(const char *key, int len);

// Thomas Wang’s 32-bit Mix
u32 hash_32bit_mix(u32 value);

// Mid-Square Method
u32 hash_midsquare(u32 value, u32 capacity);

// Digit Folding Method
u32 hash_folding(u32 value, u32 capacity);

#endif