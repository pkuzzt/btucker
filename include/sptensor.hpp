#ifndef SPTUCKER_SPTENSOR_HPP
#define SPTUCKER_SPTENSOR_HPP

#include "read_data.hpp"
#include <cstdlib>

class coo_tensor {
public:
    size_t nnz;
    size_t ndim;
    size_t *dims;
    size_t **index_lists;
    double *vals;
    explicit coo_tensor(data_buffer *dbf);
};
#endif //SPTUCKER_SPTENSOR_HPP
