#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>

class Matrix {
private:
    int n;
    std::vector<double> data;

public:
    Matrix(int size);
    int size() const;

    double& operator()(int i, int j);
    const double& operator()(int i, int j) const;

    static Matrix readFromFile(const std::string& filename);
    void writeToFile(const std::string& filename) const;

    Matrix operator*(const Matrix& other) const;
};

#endif