#include "hhsum.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std; 

 
// Driver code 
int main() 
{
  int n, nn;
  double k, t, theta, c, del;
/* double* x = new double[n];
x[0]=-5.1; x[1]=2.3; x[2]=3.7; x[3]=1.1; x[4]=0.7;
double norm1;
double norminf;
norms(x,n,norm1,norminf);
cout << "norm1 = " << norm1 << endl;
cout << "norminf = " << norminf << endl;
delete[] x;*/

  hhsum hhs1;


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

  //cout << "kernel is "<< kernel(n,k,theta,c,del) << endl;

      cout  << "           N          n       kernel_n     gamma_n      h_n          h           error";
   //   std::cout << "         l1       l2" << endl;
   //   std::cout << "                 answer1      answer1";
      cout << "  " << "  " << endl << endl;

      cout << fixed << setprecision(6);

  double sum1 = 0.0;
  double sum2 = 0.0;


  for (int i=0; i<n; i++){
    for (int j=1; j<nn+1; j++){
      sum1 += pow(hhs1.kernel(i,k,theta,c,del),j)* hhs1.series(i,t-i);
      sum2 += (1/del)*pow(hhs1.kernel(i,k,theta,c,del),j)* hhs1.series(i,t*(1/del)-i);
      cout << setw(12) << j << setw(12) << i << setw(13) << pow(hhs1.kernel(i,k,theta,c,del),j) << setw(12) << hhs1.series(i,t-i) << setw(13)<< sum1 << setw(13) << sum2 << setw(13) << hhs1.findError(sum2,sum1);
      cout << endl;
    }
  }

  return 0;
  }
/* 
Under beta_j = g((j+1)del)
 Enter the value for t: 3.5
 Enter the value for n (n>=0): 4
 Enter the value for N (N>=1): 3
 Enter the value for k: 0.6
 Enter the value for theta: 0.8
 Enter the value for c: 1.1
 Enter the value for delta: 0.001
norm1 = 12.2
norminf = 5.1
           N          n       kernel_n     gamma_n      h_n          h           error    

           1           0     0.435650    0.285714     0.124472     0.124472     0.000000
           2           0     0.189791    0.285714     0.178698     0.178698     0.000000
           3           0     0.082683    0.285714     0.202321     0.202321     0.000000
           1           1     0.434939    0.000000     0.202321     0.202321     0.000000
           2           1     0.189172    0.000000     0.202321     0.202321     0.000000
           3           1     0.082278    0.000000     0.202321     0.202321     0.000000
           1           2     0.434230    0.500000     0.419436     0.202321     0.217115
           2           2     0.188555    0.500000     0.513714     0.202321     0.311393
           3           2     0.081876    0.500000     0.554652     0.202321     0.352331
           1           3     0.433522    0.125000     0.608842     0.202321     0.406521
           2           3     0.187941    0.125000     0.632335     0.202321     0.430014
           3           3     0.081477    0.125000     0.642519     0.202321     0.440198
*/