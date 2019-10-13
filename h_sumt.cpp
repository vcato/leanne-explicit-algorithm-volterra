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
        //cout << mPow * comb * myfct / n1fact << " ";
        sum += mPow * comb * myfct/ n1fact;
    }
    return sum;
}

double h_series(double k, double tt, double t){
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
   // cout << h_series(0.3,2.9,0.8) << endl;
   // cout << h_series(0.3,3.567,0.8) << endl;
   // cout << h_series(0.3,4.788,0.8) << endl;

 for (int i=1; i<floor(tt)+1; i++ ){
    cout << setw(12) << i << setw(13) << series(i,t) << setw(13) << h_series(k,i,t);
    //cout << setw(12);
    //series(n,h*i);
    cout << endl;
 }

    return 0; 
} 

/* 
leanne@leanne-HP-ProBook-450-G5:~/explicit-algorithm-volterra$ ./test
 Enter the value for t: 1.2
 Enter the value for T (T>=1): 9.8
 Enter the value for k: 0.7
           1            0     0.833333
           2          0.8      1.22533
           3         0.66      1.22533
           4     0.282667       1.2932
           5    0.0860667       1.2932
           6      0.02072      1.29564
           7   0.00414658      1.29564
           8  0.000710928      1.29568
           9  0.000106642      1.29568

leanne@leanne-HP-ProBook-450-G5:~/explicit-algorithm-volterra$ ./test
 Enter the value for t: 1.2
 Enter the value for T (T>=1): 9.8
 Enter the value for k: 0.7
           1            0     0.833333
           2          0.8      1.22533
           3         0.66      1.22533
           4     0.282667       1.2932
           5    0.0860667       1.2932
           6      0.02072      1.29564
           7   0.00414658      1.29564
           8  0.000710928      1.29568
           9  0.000106642      1.29568
*/