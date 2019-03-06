#pragma once
#include <iostream>


template <typename Type>
Type* memcpy(Type *s1, Type const* s2, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        s1[i] = s2[i];
    }
    return s1;
}

template <typename Type>
Type *resize(const Type *str, size_t size, size_t new_size)
{
    Type * new_str = new Type[new_size];
    for(int i = 0; i < size && i < new_size; ++i)
        new_str[i] = str[i];
    delete[] str;
 
    return new_str;
}
