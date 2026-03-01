#include "matrix.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

Matrix::Matrix(int size) : n(size), data(size * size, 0.0) {}

int Matrix::size() const {
    return n;
}

double& Matrix::operator()(int i, int j) {
    return data[i * n + j];
}

const double& Matrix::operator()(int i, int j) const {
    return data[i * n + j];
}

Matrix Matrix::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file)
        throw std::runtime_error("Cannot open file: " + filename);

    int size;
    file >> size;

    Matrix m(size);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            file >> m(i, j);

    return m;
}

void Matrix::writeToFile(const std::string& filename) const {
    std::ofstream file(filename);
    file << n << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            file << (*this)(i, j) << " ";
        file << "\n";
    }
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (n != other.n)
        throw std::runtime_error("Matrix sizes do not match");

    Matrix result(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                result(i, j) += (*this)(i, k) * other(k, j);

    return result;
}