// hhsum.hpp
#ifndef HHSUM_HPP // include guard
#define HHSUM_HPP

#include <string>

class hhsum{
public: //member functions
	int nCr(int n, int r);
	int fact(int n); 
	double rect(double t, double low, double up);
	double impul(double t);
	double my_fct(double t, double a, double k);
	double series(int n, double t);
	double kernel(int n, double k, double theta, double c, double del);
	void norms(double* x, int n, double& norm1, double& norminf);

private: // input data
	int r, a, n, nn;
	double k, t, theta, c, low, up, del, h;
};

#endif