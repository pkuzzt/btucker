//
// Created by 30250 on 2022/3/13.
//
#include "read_data.hpp"
#include "def.hpp"
#include <cstdlib>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <cstdio>

int read_int(const char* cbf, size_t &i) {
    char str[20];
    int j = 0;
    while (cbf[i] >= '0' && cbf[i] <= '9') {
        str[j++] = cbf[i++];
    }
    str[j] = '\0';
    i++;
    return atoi(str);
}

double read_double(const char *cbf, size_t &i) {
    char str[20];
    int j = 0;
    while ((cbf[i] >= '0' && cbf[i] <= '9') || cbf[i] == '.') {
        str[j++] = cbf[i++];
    }
    str[j] = '\0';
    i++;
    return atof(str);
}

void read_data(char* filename, data_buffer *dbf) {
    int infile = open(filename, O_RDONLY);
    struct stat statbuf;
    size_t filesize, nnz, k;
    size_t ndim = 0, i, j;

    if (!infile) {
        fprintf(stderr, "Error: Can not find file: %s\n", filename);
        my_exit(FILE_NAME_ERROR);
    }
    stat(filename, &statbuf);
    filesize = statbuf.st_size;

    fprintf(stdout, "filename  : %s\n", filename);
    fprintf(stdout, "size      : %lu\n", filesize);
    char* cbf = (char*) mmap(nullptr, filesize, PROT_READ, MAP_PRIVATE, infile, 0);
    if (cbf == MAP_FAILED) {
        my_exit(MMAP_ERROR);
    }

    i = 0;nnz = 0;
    while (true) {
        char ch = cbf[i++];
        if (ch == ' ') {
            ndim++;
        }
        if (ch == '\n') {
            break;
        }
    }

    for (i = 0; i < filesize; i++) {
        if (cbf[i] == '\n') {
            nnz++;
        }
    }
    fprintf(stdout, "ndim      : %lu\n", ndim);
    fprintf(stdout, "nnz       : %lu\n", nnz);

    dbf->ndim = ndim;
    dbf->nnz = nnz;
    dbf->index_lists = (size_t**) malloc(sizeof(size_t*) * ndim);
    for (i = 0; i < ndim; i++) {
        dbf->index_lists[i] = (size_t*) malloc(sizeof(size_t) * nnz);
    }
    dbf->vals = (double*) malloc(sizeof(double) * nnz);

    k = 0;
    for (i = 0; i < nnz; i++) {
        for (j = 0; j < ndim; j++) {
            dbf->index_lists[j][i] = read_int(cbf, k) - 1;
        }
        dbf->vals[i] = read_double(cbf, k);
    }
}

