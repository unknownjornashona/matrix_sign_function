#include "MatrixSignFunction.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <complex>

MatrixSignFunction::MatrixSignFunction(const MatrixXd &matrix, int samplePoints)
    : A(matrix), N(samplePoints) {
    if (A.rows() != A.cols()) {
        throw std::invalid_argument("Input matrix must be square.");
    }
}

MatrixXd MatrixSignFunction::computeSignFunction() {
    const double pi = 3.14159265358979323846;
    MatrixXd result = MatrixXd::Zero(A.rows(), A.cols());

    for (int j = 0; j < N; ++j) {
        double theta = 2 * pi * j / N;
        std::complex<double> z(cos(theta), sin(theta));

        MatrixXd I = MatrixXd::Identity(A.rows(), A.cols());
        std::complex<double> determinant = (I - z * A).determinant();
        if (std::abs(determinant) < 1e-10) {
            throw std::runtime_error("Matrix inversion failed due to determinant close to zero.");
        }
        result += (I - z * A).inverse().real();
    }

    result /= N;  // 平均を取る
    return result;
}

void MatrixSignFunction::saveToCSV(const std::string &filename, const MatrixXd &matrix) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file for writing.");
    }
    
    for (int i = 0; i < matrix.rows(); ++i) {
        for (int j = 0; j < matrix.cols(); ++j) {
            file << std::fixed << std::setprecision(6) << matrix(i, j);
            if (j < matrix.cols() - 1) file << ",";
        }
        file << "\n";
    }
    file.close();
}

void MatrixSignFunction::log(const std::string &message) {
    std::ofstream logFile("log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << message << "\n";
        logFile.close();
    }
}
