#include "lsr.h"
#include <iostream>
#include <numeric>

void simple_linear_regression::print(std::string message)
{
    std::cout << message << "\n";
}

void simple_linear_regression::calculate_N()
{
    if (X.size() == y.size())
    {
        N = X.size();
    }
    else
    {
        throw "SIZE MISMATCH: X and y must be the same size.";
    }
}

/// Calculates X squared and saves it to XX vector
void simple_linear_regression::x_square()
{
    print("Calculating X * X");

    for (double i : X)
    {
        XX.push_back(i * i);
    }
}

/// Calculates X * y and stores in Xy
void simple_linear_regression::x_cross_y()
{
    print("Calculating X * y"); 
    for (int i = 0; i < N; i++)
    {
        Xy.push_back(X[i] * y[i]);
    }
}

void simple_linear_regression::calculate_sigma()
{
    print("Calculating sum of X");
    sigma_X = std::accumulate(X.begin(), X.end(), 0.0);

    print("Calculating sum of y");
    sigma_y = std::accumulate(y.begin(), y.end(), 0.0);

    print("Calculating sum of XX");
    sigma_XX = std::accumulate(XX.begin(), XX.end(), 0.0);

    print("Calculating sum of Xy");
    sigma_Xy = std::accumulate(Xy.begin(), Xy.end(), 0.0);
}

// Calculate the value of m (slope/a_1)
void simple_linear_regression::calculate_slope()
{
    print("Calculating a1 (slope)");

    m = ((N * sigma_Xy) - (sigma_X * sigma_y)) / ((N * sigma_XX) - (sigma_X * sigma_X));
}

void simple_linear_regression::calculate_bias()
{
    print("Calculate a0 (bias or intercept)");

    b = (sigma_y - (m * sigma_X)) / N;
}

// constructor for training new model
// constructor for start training new model
simple_linear_regression::simple_linear_regression(std::vector<double> X, std::vector<double> y) : X(X), y(y) {}

void simple_linear_regression::train()
{
    print("Training");

    calculate_N();
    x_square();
    x_cross_y();
    calculate_sigma();
    calculate_slope();
    calculate_bias();

    print("Finalized Training");
}

double simple_linear_regression::predict(double _X)
{
    return (m * _X) + b;
}

int main()
{

    std::vector<double> X = {2.0, 3.0, 5.0, 7.0, 9.0};
    std::vector<double> y = {4.0, 5.0, 7.0, 10.0, 15.0};
    simple_linear_regression slr(X, y);
    slr.train();

    std::cout << slr.predict(8.0);

    return 0;
}
