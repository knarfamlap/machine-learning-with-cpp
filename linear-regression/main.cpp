#include <vector>
#include <eigen3/Eigen/Core>
#include "LinearRegression.h"

using namespace Eigen;

int main()
{

    // std::vector<double> X = {2.0, 3.0, 5.0, 7.0, 9.0};
    // std::vector<double> y = {4.0, 5.0, 7.0, 10.0, 15.0};
    // LinearRegression slr(X, y);
    // slr.train();

    // std::cout << slr.predict(15.0);

    MatrixXd X = MatrixXd::Random(5, 5);
    MatrixXd y = MatrixXd::Random(5, 1);
    X.transposeInPlace();
    // MatrixXd res = X * X;

    std::cout << X << std::endl; 

    return 0;
}
