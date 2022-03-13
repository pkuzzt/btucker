#include "sptensor.hpp"
#include <cstdio>
coo_tensor::coo_tensor(data_buffer *dbf) {
    this->ndim = dbf->ndim;
    this->index_lists = dbf->index_lists;
    this->vals = dbf->vals;
    this->nnz = dbf->nnz;
    this->dims = (size_t*) malloc(sizeof(size_t) * this->ndim);
    for (size_t mode = 0; mode < this->ndim; mode++) {
        for (size_t i = 0; i < this->nnz; i++) {
            dims[mode] = max(dims[mode], this->index_lists[mode][i]);
        }
    }
    for (size_t i = 0; i < this->ndim; i++) {
        fprintf(stdout, "%lu\n", this->dims[i]);
    }
}