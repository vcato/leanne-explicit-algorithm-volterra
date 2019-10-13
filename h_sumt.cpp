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
double my_fct(double t, int a, int k);
double series(int n, double t);
double h_series(int k, double tt, double t);
void max_ser(int n, double t);

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

double rect(double t, double low, double up){
	return ((t>=low)  && (t< up)? 1 : 0);
}

double impul(double t){
	return (t==0 ? 1 : 0);
}

/*double taPow(double a, double r){
    return pow(t-a, r)
}*/

double my_fct(double t, int a, int k){
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
        //cout << mPow * comb * myfct / n1fact << " ";
        sum += mPow * comb * myfct/ n1fact;
    }
    return sum;
}

double h_series(int k, double tt, double t){
  double sum = 0.0;
  for ( i= 0; i < floor(tt)+1; i++) {
    double kPow = pow(k, i);
    double g_ser = series (i, t);
    sum +=  kPow*g_ser;
  }
  return sum;

}

  
// Driver code 
int main() 
{ 
 double t, tt; 
 double h;
 //h = static_cast<float>(t)/nn;
    cout <<" Enter the value for t: ";
    cin >> t;
 //   cout <<" Enter the value for n (n>=1): ";
    cout <<" Enter the value for T (T>=1): ";
    cin >> tt;
    cout <<" Enter the value for k: ";
    cin >> k;
 for (int i=0; i<tt; i++ ){
    cout << setw(12) << i << setw(13) << series(i,t) << setw(13) << h_series(k,tt,t);
    //cout << setw(12);
    //series(n,h*i);
    cout << endl;
 }

    return 0; 
} 

/* 
leanne@leanne-HP-ProBook-450-G5:~/explicit-algorithm-volterra$ ./test
 Enter the value for t: 1.3
 Enter the value for T (T>=1): 9.6
 Enter the value for k: 0.3
           0     0.769231     0.769231
           1            0     0.769231
           2          0.7     0.769231
           3         0.71     0.769231
           4     0.348167     0.769231
           5     0.117317     0.769231
           6    0.0308196     0.769231
           7   0.00669681     0.769231
           8   0.00124466     0.769231
           9    0.0002023     0.769231
*/