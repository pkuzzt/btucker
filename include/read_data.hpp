#ifndef SPTUCKER_READ_DATA_HPP
#define SPTUCKER_READ_DATA_HPP
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;
class data_buffer {
public:
    size_t ** index_lists;
    double * vals;
    size_t ndim;
    size_t nnz;
};

void read_data(char* filename, data_buffer *dbf);

#endif
