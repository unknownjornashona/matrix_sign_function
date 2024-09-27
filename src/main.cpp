#include "MatrixSignFunction.h"
#include <iostream>

int main() {
    try {
        MatrixXd A(2, 2);
        A << 0, -1,
             1, 0;

        int samplePoints = 100;
        MatrixSignFunction msf(A, samplePoints);
        
        MatrixXd signA = msf.computeSignFunction();
        std::cout << "Matrix Sign Function:\n" << signA << std::endl;

        // 結果をCSVファイルに保存
        msf.saveToCSV("sign_function.csv", signA);
        
        // ログを記録
        msf.log("Matrix sign function computation completed successfully.");

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
