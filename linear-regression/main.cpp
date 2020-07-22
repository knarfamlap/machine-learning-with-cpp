#include <vector>
#include <eigen/Eigen/Core>
#include "LinearRegression.h"

using namespace Eigen;

int main()
{

    // std::vector<double> X = {2.0, 3.0, 5.0, 7.0, 9.0};
    // std::vector<double> y = {4.0, 5.0, 7.0, 10.0, 15.0};
    // LinearRegression slr(X, y);
    // slr.train();

    // std::cout << slr.predict(15.0);

    MatrixXd X  = MatrixXd::Random(5, 5); 
    MatrixXd y = MatrixXd::Random(5, 1); 
    X.transposeInPlace(); 
    X.dot(X); 
    
      

    MatrixXd ones = MatrixXd::Ones(y.rows(), 1);
    y.conservativeResize(y.rows(), y.cols() + 1); 
    y.col(y.cols() - 1) = ones; 

    std::cout << y << std::endl;

    std::cout << y.cols() << std::endl;
    return 0;
}
