#include "hhsum.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std; 

 
// Driver code 
int main() 
{
  int n, nn;
  double k, t, theta, c, del;
  std::string base;


  hhsum hhs1;

  cout <<" Enter kernel: ";
  cin >> base;

  cout <<" Enter the value for t: ";
  cin >> t;
  //   cout <<" Enter the value for n (n>=1): ";
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


      cout  << "           N          n       kernel_n     gamma_n      h_n          h           error";
      cout << "  " << "  " << endl << endl;

      cout << fixed << setprecision(6);

  double sum1 = 0.0;
  double sum2 = 0.0;


  for (int i=0; i<n; i++){
    for (int j=1; j<nn+1; j++){
      sum1 += pow(hhs1.kernel(i,k,theta,c,del,base),j)* hhs1.series(i,t-i);
      sum2 += (1/del)*pow(hhs1.kernel(i,k,theta,c,del,base),j)* hhs1.series(i,t*(1/del)-i);
      cout << setw(12) << j << setw(12) << i << setw(13) << pow(hhs1.kernel(i,k,theta,c,del,base),j) << setw(12) << hhs1.series(i,t-i) << setw(13)<< sum1 << setw(13) << sum2 << setw(13) << hhs1.findError(sum2,sum1);
      cout << endl;
    }
  }

  return 0;
  }
/* 
 Enter kernel: Exp
 Enter the value for t: 3.5
 Enter the value for n (n>=0): 4
 Enter the value for N (N>=1): 3
 Enter the value for k: 0.4
 Enter the value for theta: 0.8
 Enter the value for c: 1.1
 Enter the value for delta: 0.001
norm1 = 12.2
norminf = 5.1
           N          n       kernel_n     gamma_n      h_n          h           error    

           1           0     0.320000    0.285714     0.091429     0.091429     0.000000
           2           0     0.102400    0.285714     0.120686     0.120686     0.000000
           3           0     0.032768    0.285714     0.130048     0.130048     0.000000
           1           1     0.320000    0.000000     0.130048     0.130048     0.000000
           2           1     0.102400    0.000000     0.130048     0.130048     0.000000
           3           1     0.032768    0.000000     0.130048     0.130048     0.000000
           1           2     0.320000    0.500000     0.290048     0.130048     0.160000
           2           2     0.102400    0.500000     0.341248     0.130048     0.211200
           3           2     0.032768    0.500000     0.357632     0.130048     0.227584
           1           3     0.320000    0.125000     0.397632     0.130048     0.267584
           2           3     0.102400    0.125000     0.410432     0.130048     0.280384
           3           3     0.032768    0.125000     0.414528     0.130048     0.284480

*/