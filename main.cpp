#include "Matrix.hpp"
#include <iostream>
using namespace std;

int main() {
    // Define matrices a, b, and c for testing
    Matrix a({
        {1, 2},
        {3, 4}
        });

    Matrix b({
        {5, 6},
        {7, 8}
        });

    Matrix c({
        {2, 0},
        {1, 2}
        });

    // doing d = a + (3 * b) * cᵗ
    Matrix scalar_b = b * 3;         // 3 * b
    Matrix ct = c.transpose();       // cᵗ
    Matrix mul = scalar_b * ct;      // (3 * b) * cᵗ
    Matrix d = a + mul;              // a + ((3 * b) * cᵗ)

    cout << "Matrix a:\n";
    a.print();

    cout << "\nMatrix b:\n";
    b.print();

    cout << "\nMatrix c:\n";
    c.print();

    cout << "\n3 * b:\n";
    scalar_b.print();

    cout << "\nTranspose of c:\n";
    ct.print();

    cout << "\n(3 * b) * cᵗ:\n";
    mul.print();

    cout << "\nFinal result d = a + (3 * b) * cᵗ:\n";
    d.print();

    return 0; //don't remember if this is necessary
}
