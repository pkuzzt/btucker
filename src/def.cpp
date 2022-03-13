//
// Created by 30250 on 2022/3/13.
//

#include "def.hpp"
void my_exit(int code) {
    fprintf(stderr, "Process exits with error code: %d \n", code);
    exit(code);
};

void* my_malloc(size_t length) {
    void *buf = malloc(length);
    if (!buf) {
        my_exit(MALLOC_ERROR);
    }
    return buf;
}