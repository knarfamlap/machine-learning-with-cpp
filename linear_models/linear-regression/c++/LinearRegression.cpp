#include "LinearRegression.h"
#include <iostream>
#include <numeric>
#include <eigen3/Eigen/Core>

using namespace Eigen;

void LinearRegression::print(std::string message)
{
    std::cout << message << "\n";
}

void LinearRegression::calculate_N()
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
void LinearRegression::x_square()
{
    print("Calculating X * X");

    for (double i : X)
    {
        XX.push_back(i * i);
    }
}

/// Calculates X * y and stores in Xy
void LinearRegression::x_cross_y()
{
    print("Calculating X * y");
    for (int i = 0; i < N; i++)
    {
        Xy.push_back(X[i] * y[i]);
    }
}

void LinearRegression::calculate_sigma()
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
void LinearRegression::calculate_slope()
{
    print("Calculating a1 (slope)");

    m = ((N * sigma_Xy) - (sigma_X * sigma_y)) / ((N * sigma_XX) - (sigma_X * sigma_X));
}

void LinearRegression::calculate_bias()
{
    print("Calculate a0 (bias or intercept)");

    b = (sigma_y - (m * sigma_X)) / N;
}

// makes the row vector into a column vector
// should only be used if X has 1 column
MatrixXd LinearRegression::reshapeX(MatrixXd X)
{
    // makes the row vector into a column vector
    X.transposeInPlace();
    return X;
}

// adds column vector of ones to the end of X
MatrixXd LinearRegression::concatenateOnes(MatrixXd X)
{
    // create a column vector of 1s with row number from X
    MatrixXd ones = MatrixXd::Ones(X.rows(), 1);
    // adds 1 column placeholder to the right
    X.conservativeResize(X.rows(), X.cols() + 1);
    // assign the colum of ones to the end
    X.col(X.cols() - 1) = ones;

    return X;
}

void LinearRegression::fit(MatrixXd X, Matrix<double, Dynamic, 1> y)
{
    if (X.rows() == 1)
    {
        X = reshapeX(X); 
    }

    X = concatenateOnes(X); 
    
}

LinearRegression::LinearRegression()
{
    coefficients = std::vector<double>();
}

// constructor for training new model
// constructor for start training new model
LinearRegression::LinearRegression(std::vector<double> X, std::vector<double> y) : X(X), y(y) {}

void LinearRegression::train()
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

double LinearRegression::predict(double _X)
{
    return (m * _X) + b;
}