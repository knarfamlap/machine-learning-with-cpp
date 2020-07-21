/// Frank Palma Gomez
#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class LinearRegression
{
private:
	int N = 0;

	std::vector<double> X;
	std::vector<double> y;

	std::vector<double> XX;
	std::vector<double> Xy;

	double sigma_X = 0.0;
	double sigma_y = 0.0;
	double sigma_XX = 0.0;
	double sigma_Xy = 0.0;

	// slope
	double m = 0.0;

	// intercept
	double b = 0.0;

	// methods
	void print(std::string message);

	void calculate_N();

	void x_square();
	void x_cross_y();

	void calculate_sigma();

	void calculate_slope();

	void calculate_bias();

public:
	LinearRegression(std::vector<double> X, std::vector<double> y);
	void train();
	double predict(double _X);
};