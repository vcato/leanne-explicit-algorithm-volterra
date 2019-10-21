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

      cout  << "           N          n       kernel_n     gamma_n      h_n";
   //   std::cout << "         l1       l2" << endl;
   //   std::cout << "                 answer1      answer1";
      cout << "  " << "  " << endl << endl;

      cout << fixed << setprecision(6);

  double sum = 0.0;

  for (int i=0; i<n; i++){
    for (int j=1; j<nn+1; j++){
      sum += pow(hhs1.kernel(i,k,theta,c,del),j)* hhs1.series(i,t-i);
      cout << setw(12) << j << setw(12) << i << setw(13) << pow(hhs1.kernel(i,k,theta,c,del),j) << setw(12) << hhs1.series(i,t-i) << setw(13) << setw(13)<< sum;
      cout << endl;
    }
  }

  return 0;
  }
/* 
 leanne@leanne-HP-ProBook-450-G5:~/explicit-algorithm-volterra/approxh$ ./hhsum
 Enter the value for t: 3.5
 Enter the value for n (n>=0): 4
 Enter the value for N (N>=1): 3
 Enter the value for k: 0.6
 Enter the value for theta: 0.8
 Enter the value for c: 1.1
 Enter the value for delta: 0.01
norm1 = 12.2
norminf = 5.1
           N          n       kernel_n     gamma_n      h_n    

           1           0     0.436364    0.285714     0.124675
           2           0     0.190413    0.285714     0.179079
           3           0     0.083089    0.285714     0.202819
           1           1     0.429313    0.000000     0.202819
           2           1     0.184310    0.000000     0.202819
           3           1     0.079127    0.000000     0.202819
           1           2     0.422438    0.500000     0.414038
           2           2     0.178454    0.500000     0.503265
           3           2     0.075386    0.500000     0.540958
           1           3     0.415733    0.125000     0.592924
           2           3     0.172834    0.125000     0.614528
           3           3     0.071853    0.125000     0.623510
*/