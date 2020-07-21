#include <vector>
#include "LinearRegression.h"

int main()
{

    std::vector<double> X = {2.0, 3.0, 5.0, 7.0, 9.0};
    std::vector<double> y = {4.0, 5.0, 7.0, 10.0, 15.0};
    LinearRegression slr(X, y); 
    slr.train();

    std::cout << slr.predict(15.0);

    return 0;
}
