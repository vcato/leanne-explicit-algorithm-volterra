#include <iostream>
#include <cmath>
using namespace std; 

void norms(double* x, int n, double& norm1, double& norminf)
{
  norm1 = fabs(x[0]);
  norminf = norm1;
  for(int i=1; i<n; i++)
  {
    x[i] = fabs(x[i]);
    norm1 += x[i];
    if(x[i]> norminf)
      norminf = x[i]; 
  }
}


int main() 
{
	int n, nn;
	double t, k, theta, c, del; 
	double h;
	double* x = new double[n];
	x[0]=-5.1; x[1]=2.3; x[2]=3.7; x[3]=1.1; x[4]=0.7;
	double norm1;
	double norminf;
	norms(x,n,norm1,norminf);
	cout << "norm1 = " << norm1 << endl;
	cout << "norminf = " << norminf << endl;
	delete[] x;
	return 0;
}
