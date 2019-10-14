#include <bits/stdc++.h> 
#include <iostream>
#include <cmath>
using namespace std; 


// Global Declaration Section
int n, r, a, k, i; double t, low, up;

 
 // Function Declaration  
int nCr(int n, int r);
int fact(int n); 
double rect(double t, double low, double up);
double impul(double t);
double my_fct(double t, double a, double k);
double series(int n, double t);
double h_series(double k, double tt, double t);

// Function definition
int nCr(int n, int r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
} 
  
// Returns factorial of n 
int fact(int n) 
{ 
    int res = 1; 
    for (int i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 

double my_fct(double t, double a, double k){
    return (t>= a ? pow(t-a, k) : 0);
}

double series(int n, double t){
// calculating the value of (n-1)!

    int n1fact = fact(n-1);
    double sum = 0.0;

// loop to display the series
    for ( i=0; i<n+1; i++) {

        int mPow = pow(-1,i);
        int comb = nCr(n, i);
        double myfct = my_fct(t,i,n-1);
        sum += mPow * comb * myfct/ n1fact;
    }
    return sum;
}

double h_series(double k, double tt, double t){
  double sum = 0.0;
  for ( i= 1; i < floor(tt)+1; i++) {
    double kPow = pow(k, i);
    double g_ser = series (i, t);
    sum +=  kPow*g_ser;
  }
  return sum;

}
  
// Driver code 
int main() 
{ 
 double t, tt, k; 
 double h;
 //h = static_cast<float>(t)/nn;
    cout <<" Enter the value for t: ";
    cin >> t;
 //   cout <<" Enter the value for n (n>=1): ";
    cout <<" Enter the value for T (T>=1): ";
    cin >> tt;
    cout <<" Enter the value for k: ";
    cin >> k;
 
 for (int i=1; i<floor(tt)+1; i++ ){
    cout << setw(12) << i << setw(13) << series(i,t) << setw(13) << h_series(k,i,t);
    //cout << setw(12);
    //series(n,h*i);
    cout << endl;
 }

    return 0; 
} 

/* 
leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ ./test
 Enter the value for t: 0.8
 Enter the value for T (T>=1): 7.3
 Enter the value for k: 0.7
           1            1          0.7
           2          0.8          0.7
           3         0.32      0.80976
           4    0.0853333      0.80976
           5    0.0170667     0.812628
           6   0.00273067     0.812628
           7  0.000364089     0.812658

*/