/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================
   Description:
    This file contains the hash functions for integer and string keys.
   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h
    - 2025/11/21: Complete final modification
   Developer: Yan-Xi Lee <leesteve0312@gmail.com>
   The program development process was partially assisted by ChatGPT.
 */
#include "hash_fn.h"
/*
 Integer Hash Function
 Method: Multiplication Method
 */
int myHashInt(int key, int m) 
{
    double A = 0.7;
    double frac = (key * A) - (int)(key * A);
    return (int)(m * frac);
}
/*
 String Hash Function
 Method: Polynomial Rolling Hash
 hash = (hash * 31 + current_char) % m
 */
int myHashString(const char* str, int m) 
{
    unsigned long hash = 0;
    while (*str) 
    {
        hash = (hash * 31 + (unsigned char)(*str)) % m;
        str++;
    }
    return (int)hash;
}
