#include "Matrix.hpp"
#include <iomanip>
using namespace std;

Matrix::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
    data.resize(rows, vector<double>(cols, 0.0));
}

Matrix::Matrix(const vector<vector<double>>& input) {
    if (input.empty() || input[0].empty())
        throw invalid_argument("Matrix dimensions cannot be zero.");

    rows = input.size();
    cols = input[0].size();

    for (const auto& row : input) {
        if (row.size() != cols)
            throw invalid_argument("Inconsistent row sizes.");
    }

    data = input;
}

size_t Matrix::getRows() const { return rows; }
size_t Matrix::getCols() const { return cols; }

double& Matrix::at(size_t row, size_t col) {
    if (row >= rows || col >= cols)
        throw out_of_range("Index out of bounds.");
    return data[row][col];
}

double Matrix::at(size_t row, size_t col) const {
    if (row >= rows || col >= cols)
        throw out_of_range("Index out of bounds.");
    return data[row][col];
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols)
        throw invalid_argument("Matrix dimensions must match.");

    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            result.at(i, j) = this->at(i, j) + other.at(i, j);
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols)
        throw invalid_argument("Matrix dimensions must match.");

    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            result.at(i, j) = this->at(i, j) - other.at(i, j);
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows)
        throw invalid_argument("Invalid matrix dimensions for multiplication.");

    Matrix result(rows, other.cols);
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < other.cols; ++j)
            for (size_t k = 0; k < cols; ++k)
                result.at(i, j) += this->at(i, k) * other.at(k, j);
    return result;
}

Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            result.at(i, j) = this->at(i, j) * scalar;
    return result;
}

Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            result.at(j, i) = this->at(i, j);
    return result;
}

void Matrix::print() const {
    for (const auto& row : data) {
        for (double val : row)
            cout << val << " ";
        cout << '\n';
    }
}
