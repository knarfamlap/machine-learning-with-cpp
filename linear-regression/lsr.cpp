#include "lsr.h"

void simple_linear_regression::print(std::string message)
{
    if (verbose)
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
    for (double i : X)
    {
        sigma_X += i;
    }

    print("Calculating sum of y");
    for (double i : y)
    {
        sigma_y += i;
    }

    print("Calculating sum of XX");
    for (double i : XX)
    {
        sigma_XX += i;
    }

    print("Calculating sum of Xy");
    for (double i : Xy)
    {
        sigma_Xy += i;
    }
}

// Calculate the value of m (slope/a_1)
void simple_linear_regression::calculate_slope()
{
    print("Calculating a1 (slope)");

    m = ((N * sigma_Xy) - (sigma_X * sigma_y)) / ((N * sigma_XX) - (sigma_X * sigma_X));
}

void simple_linear_regression::calculate_bias()
{
    print("Calculate a0 (bias or intercept");

    b = (sigma_y - (m * sigma_X)) / N;
}

// constructor for training new model
simple_linear_regression::simple_linear_regression(std::vector<double> X, std::vector<double> y, bool verbose)
{
    this->X = X;
    this->y = y;
    this->verbose = verbose;
}

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
