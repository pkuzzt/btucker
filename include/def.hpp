#ifndef SPTUCKER_DEF_HPP
#define SPTUCKER_DEF_HPP
#include <stdio.h>
#include <stdlib.h>
enum ERROR_FLAG{
    FILE_NAME_ERROR = 1,
    MALLOC_ERROR = 2,
    MMAP_ERROR = 3
};

void my_exit(int code);
void* my_malloc(size_t length);
#endif