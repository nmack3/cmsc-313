#include "matrixb.h"
#include <stdio.h>
#include <stdlib.h>

Matrix* matrix_create(size_t rows, size_t cols) {
    Matrix* m = malloc(sizeof(Matrix));
    if (!m) return NULL;

    m->rows = rows;
    m->cols = cols;

    m->data = malloc(rows * sizeof(double*));
    if (!m->data) {
        free(m);
        return NULL;
    }

    for (size_t i = 0; i < rows; ++i) {
        m->data[i] = calloc(cols, sizeof(double));
        if (!m->data[i]) {
            for (size_t j = 0; j < i; ++j) free(m->data[j]);
            free(m->data);
            free(m);
            return NULL;
        }
    }

    return m;
}

Matrix* matrix_from_array(double* values, size_t rows, size_t cols) {
    Matrix* m = matrix_create(rows, cols);
    if (!m) return NULL;

    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            m->data[i][j] = values[i * cols + j];

    return m;
}

void matrix_free(Matrix* m) {
    if (!m) return;
    for (size_t i = 0; i < m->rows; ++i)
        free(m->data[i]);
    free(m->data);
    free(m);
}

Matrix* matrix_add(const Matrix* a, const Matrix* b) {
    if (!a || !b || a->rows != b->rows || a->cols != b->cols)
        return NULL;

    Matrix* result = matrix_create(a->rows, a->cols);
    if (!result) return NULL;

    for (size_t i = 0; i < a->rows; ++i)
        for (size_t j = 0; j < a->cols; ++j)
            result->data[i][j] = a->data[i][j] + b->data[i][j];

    return result;
}

Matrix* matrix_sub(const Matrix* a, const Matrix* b) {
    if (!a || !b || a->rows != b->rows || a->cols != b->cols)
        return NULL;

    Matrix* result = matrix_create(a->rows, a->cols);
    if (!result) return NULL;

    for (size_t i = 0; i < a->rows; ++i)
        for (size_t j = 0; j < a->cols; ++j)
            result->data[i][j] = a->data[i][j] - b->data[i][j];

    return result;
}

Matrix* matrix_mul(const Matrix* a, const Matrix* b) {
    if (!a || !b || a->cols != b->rows)
        return NULL;

    Matrix* result = matrix_create(a->rows, b->cols);
    if (!result) return NULL;

    for (size_t i = 0; i < a->rows; ++i)
        for (size_t j = 0; j < b->cols; ++j)
            for (size_t k = 0; k < a->cols; ++k)
                result->data[i][j] += a->data[i][k] * b->data[k][j];

    return result;
}

Matrix* matrix_scalar_mul(const Matrix* m, double scalar) {
    if (!m) return NULL;

    Matrix* result = matrix_create(m->rows, m->cols);
    if (!result) return NULL;

    for (size_t i = 0; i < m->rows; ++i)
        for (size_t j = 0; j < m->cols; ++j)
            result->data[i][j] = m->data[i][j] * scalar;

    return result;
}

Matrix* matrix_transpose(const Matrix* m) {
    if (!m) return NULL;

    Matrix* result = matrix_create(m->cols, m->rows);
    if (!result) return NULL;

    for (size_t i = 0; i < m->rows; ++i)
        for (size_t j = 0; j < m->cols; ++j)
            result->data[j][i] = m->data[i][j];

    return result;
}

void matrix_print(const Matrix* m) {
    if (!m) return;

    for (size_t i = 0; i < m->rows; ++i) {
        for (size_t j = 0; j < m->cols; ++j)
            printf("%.2f ", m->data[i][j]);
        printf("\n");
    }
}
