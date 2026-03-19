#ifndef NHASH_H
#define NHASH_H


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

u32 hash_mod(u32 capacity, u32 value);


#endif