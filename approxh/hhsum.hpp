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
	//double kernel(int n, double k, double theta, double c, double del, std:: string& base , const double sig = 0.5);
	double kernel(int n, double k, double t, double theta, double c, double sig, double del, std:: string& base);
	double findError(double h1,double h2);
	void norms(double* x, int n, double& norm1, double& norminf);

private: // input data
	int r, a, n, nn;
	double k, t, theta, c, sig, low, up, del, h1, h2;
	//const double sig = 0.5;
	std::string base;
};

#endif