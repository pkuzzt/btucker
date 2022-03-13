#include <stdio.h>
#include "read_data.hpp"
#include "def.hpp"
int main(int argc, char *argv[]) {
    data_buffer *dbf = (data_buffer*) my_malloc(sizeof(data_buffer));
    if (argc < 2) {
        fprintf(stderr, "Usage: ./sptucker [inputfile]\n");
    }
    else {
        read_data(argv[1], dbf);
    }

}