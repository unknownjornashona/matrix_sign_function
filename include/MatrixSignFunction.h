#ifndef MATRIX_SIGN_FUNCTION_H
#define MATRIX_SIGN_FUNCTION_H

#include <Eigen/Dense>
#include <string>
#include <stdexcept>

using namespace Eigen;

class MatrixSignFunction {
public:
    MatrixSignFunction(const MatrixXd &matrix, int samplePoints);
    MatrixXd computeSignFunction();
    void saveToCSV(const std::string &filename, const MatrixXd &matrix);
    void log(const std::string &message);

private:
    MatrixXd A;
    int N;
};

#endif // MATRIX_SIGN_FUNCTION_H
