
// fpi.hpp
#ifndef FIXED_HPP // include guard
#define FIXED_HPP


#include <string>

class FixedPoint{
public: //member functions
	void askEqn();
    double g(double x);
    void solve();
    void findError();
    void askX0();
    void display();

private: // input data
    double a,b,c;
    double Error;
    double x0,x1;
};

#endif