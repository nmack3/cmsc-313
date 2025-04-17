#ifndef MATRIXB_H
#define MATRIXB_H

#include <stddef.h> // for size_t

typedef struct {
    size_t rows;
    size_t cols;
    double** data;
} Matrix;

Matrix* matrix_create(size_t rows, size_t cols);
Matrix* matrix_from_array(double* values, size_t rows, size_t cols);
void matrix_free(Matrix* m);

Matrix* matrix_add(const Matrix* a, const Matrix* b);
Matrix* matrix_sub(const Matrix* a, const Matrix* b);
Matrix* matrix_mul(const Matrix* a, const Matrix* b);
Matrix* matrix_scalar_mul(const Matrix* m, double scalar);
Matrix* matrix_transpose(const Matrix* m);

void matrix_print(const Matrix* m);

#endif
