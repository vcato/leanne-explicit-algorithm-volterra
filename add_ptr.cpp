#include <iostream>
void add(double x, double y, double* pz);
int main()
{
double a = 1.0, b = 2.0, z;
add(a, b, &z);
std::cout << a <<" plus "<< b <<" equals "<< z <<"\n";
return 0;
}


void add(double x, double y, double* pz)
{
*pz = x + y;
}