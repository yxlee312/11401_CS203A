/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp
    - 2025/11/21: Complete final modification.
   Developer: Yan-Xi Lee <leesteve0312@gmail.com>
 */
#include "hash_fn.hpp"
#include <string>
/*  
   Integer Hash Function:
   Using multiplication method
   More uniform distribution than simple % m
*/
int myHashInt(int key, int m) 
{
    if (m <= 0) return 0;
    double A = 0.35;
    double prod = key * A;
    double frac = prod - (int)prod;
    int index = (int)(frac * m);
    if (index < 0) 
    {
    index += m; //避免負值
    }
    return index;
}
/*
   String Hash Function:
   Polynomial rolling hash
*/
int myHashString(const std::string& str, int m) 
{
    unsigned long hash = 0;
    const unsigned long p = 97;
    for (int i = 0; i < str.length(); i++) 
    {
    char c = str[i];
    hash = hash * p + (unsigned char)c;
    }
    return (int)(hash % m);
}
