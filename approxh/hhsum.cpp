#include "hhsum.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std; 



// Function definition
int hhsum::nCr(int n, int r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
} 
  
// Returns factorial of n 
int hhsum::fact(int n) 
{ 
    int res = 1; 
    for (int i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 

double hhsum::rect(double t, double low, double up){
	return ((t>=low)  && (t< up)? 1 : 0);
}

double hhsum::impul(double t){ 
	return (t==0 ? 1 : 0);
}

/*double taPow(double a, double r){
    return pow(t-a, r)
}*/

double hhsum::my_fct(double t, double a, double k){
    return (t>= a ? pow(t-a, k) : 0);
}

double hhsum::series(int n, double t){
// calculating the value of (n-1)!

    int n1fact = fact(n-1);
    double sum = 0.0;

// loop to display the series
    for ( int i=0; i<n+1; i++) {

        int mPow = pow(-1,i);
        int comb = nCr(n, i);
        double myfct = my_fct(t,i,n-1);
        sum += mPow * comb * myfct/ n1fact;
    }
    return sum;
}

//double hhsum::kernel(int n, double k, double theta, double c, double del, std:: string& base , const double sig = 0.5){
double hhsum::kernel(int n, double k, double t, double theta, double c, double sig, double del, std:: string& base){
  if(base== "PL"){
    return k*theta*pow(c,theta)/(pow((c+(n+1)*del),(1+theta)));
  }
  else if (base=="Exp"){
    return k*theta*exp(-theta*t);
  }
  else if (base=="RL"){
    //(k*t/(sig*sig))*exp(-t*t/(2*sig*sig));
    return (k*t/(pow(sig,2)))*exp(-t*t/(2*pow(sig,2)));
  }
//  return 0;
}


void hhsum::norms(double* x, int n, double& norm1, double& norminf)
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

double hhsum::findError(double h1,double h2)
{
  return fabs(h1-h2);
 }
