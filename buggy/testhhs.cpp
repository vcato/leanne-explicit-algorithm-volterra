
#include "hhsum.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std; 

 
// Driver code 
int main() 
{
  int n, nn, r;
  double k, t, theta, c, sig, del;
  std::string base;


  hhsum hhs1;

  cout <<" Enter kernel: ";
  getline (cin, base);
  //cin >> base;

  cout <<" Enter the value for t: ";
  cin >> t;
  cout <<" Enter the value for n (n>=0): ";
  cin >> n;
  cout <<" Enter the value for N (N>=1): ";
  cin >> nn;
  cout <<" Enter the value for k: ";
  cin >> k;
  cout <<" Enter the value for theta: ";
  cin >> theta;
  cout <<" Enter the value for c: ";
  cin >> c;

  cout <<" Enter the value for sigma (>=1): ";
  cin >> sig; 

  cout <<" Enter the value for delta: ";
  cin >> del;

  double* x = new double[n];
  x[0]=-5.1; x[1]=2.3; x[2]=3.7; x[3]=1.1; x[4]=0.7;
  double norm1;
  double norminf;
  hhs1.norms(x,n,norm1,norminf);
  cout << "norm1 = " << norm1 << endl;
  cout << "norminf = " << norminf << endl;
  delete[] x;


  cout  << "           N          n       beta_n     gamma_n      h_n          h           error";
  cout << "  " << "  " << endl << endl;

  cout << fixed << setprecision(6);

  double sum1 = 0.0;
  double sum2 = 0.0;

  for (int n=1; n<nn+1; n++){
    for (int r=0; r<n; r++){
      sum1 += hhs1.beta(n,r,k,theta,c,sig,del,base)* hhs1.series(n,t-r);
      sum2 += (1/del)*hhs1.beta(n,r,k,theta,c,sig,del,base)* hhs1.series(n,t*(1/del)-r);
      cout << setw(12) << n << setw(12) << r << setw(13) << hhs1.beta(n,r,k,theta,c,sig,del,base) << setw(12) << hhs1.series(n,t-r) << setw(13)<< sum1 << setw(13) << sum2 << setw(13) << hhs1.findError(sum2,sum1);
      cout << endl;
    }
  }
  return 0;
  }
/* 
 Enter kernel: RL
 Enter the value for t: 3.5
 Enter the value for n (n>=0): 4
 Enter the value for N (N>=1): 3
 Enter the value for k: 0.8
 Enter the value for theta: 0.7
 Enter the value for c: 1.1
 Enter the value for sigma (>=1): 1
 Enter the value for delta: 0.01
norm1 = 12.2
norminf = 5.1
           N          n       kernel_n     gamma_n      h_n          h           error    

           1           0     0.006125    0.285714     0.001750     0.001750     0.000000
           2           0     0.000038    0.285714     0.001761     0.001761     0.000000
           3           0     0.000000    0.285714     0.001761     0.001761     0.000000
           1           1     0.006125    0.000000     0.001761     0.001761     0.000000
           2           1     0.000038    0.000000     0.001761     0.001761     0.000000
           3           1     0.000000    0.000000     0.001761     0.001761     0.000000
           1           2     0.006125    0.500000     0.004823     0.001761     0.003062
           2           2     0.000038    0.500000     0.004842     0.001761     0.003081
           3           2     0.000000    0.500000     0.004842     0.001761     0.003081
           1           3     0.006125    0.125000     0.005608     0.001761     0.003847
           2           3     0.000038    0.125000     0.005612     0.001761     0.003852
           3           3     0.000000    0.125000     0.005612     0.001761     0.003852


*/