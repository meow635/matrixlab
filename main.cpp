#include "matrix.h"
#include <iostream>
#include <chrono>
#include <cstdlib>

int main() {
    try {
        Matrix A = Matrix::readFromFile("matrixA.txt");
        Matrix B = Matrix::readFromFile("matrixB.txt");

        auto start = std::chrono::high_resolution_clock::now();

        Matrix C = A * B;

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        C.writeToFile("result.txt");

        int N = A.size();
        long long operations = 2LL * N * N * N;

        double mflops = operations / elapsed.count() / 1e6;

        std::cout << "Matrix size: " << N << " x " << N << std::endl;
        std::cout << "Execution time: " << elapsed.count() << " seconds\n";
        std::cout << "Theoretical operations: " << operations << std::endl;
        std::cout << "Performance: " << mflops << " MFLOPS\n";

        system("py verify.py matrixA.txt matrixB.txt result.txt");

    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}