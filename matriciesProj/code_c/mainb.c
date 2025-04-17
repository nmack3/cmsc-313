#include <stdio.h>
#include "matrixb.h"

int main() {
    double a_vals[] = { 1, 2, 3, 4 };
    double b_vals[] = { 5, 6, 7, 8 };
    double c_vals[] = { 2, 0, 1, 2 };

    Matrix* a = matrix_from_array(a_vals, 2, 2);
    Matrix* b = matrix_from_array(b_vals, 2, 2);
    Matrix* c = matrix_from_array(c_vals, 2, 2);

    Matrix* b_scaled = matrix_scalar_mul(b, 3);
    Matrix* c_t = matrix_transpose(c);
    Matrix* mul = matrix_mul(b_scaled, c_t);
    Matrix* d = matrix_add(a, mul);

    printf("Matrix a:\n");
    matrix_print(a);

    printf("\nMatrix b:\n");
    matrix_print(b);

    printf("\nMatrix c:\n");
    matrix_print(c);

    printf("\n3 * b:\n");
    matrix_print(b_scaled);

    printf("\nTranspose of c:\n");
    matrix_print(c_t);

    printf("\n(3 * b) * cᵗ:\n");
    matrix_print(mul);

    printf("\nFinal result d = a + (3 * b) * cᵗ:\n");
    matrix_print(d);

    // Free all allocated matrices
    matrix_free(a);
    matrix_free(b);
    matrix_free(c);
    matrix_free(b_scaled);
    matrix_free(c_t);
    matrix_free(mul);
    matrix_free(d);

    return 0;
}
