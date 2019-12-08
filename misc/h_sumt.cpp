#include <bits/stdc++.h> 
#include <iostream>
#include <cmath>
using namespace std; 


// Global Declaration Section
int n, r, a, k, i , j; double t, low, up;

 
 // Function Declaration  
int nCr(int n, int r);
int fact(int n); 
double rect(double t, double low, double up);
double impul(double t);
double my_fct(double t, double a, double k);
double series(int n, double t);
//double h_series(double k, double tt, double t);

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


    cout  << "           n     gamma_n       h_n";
 //   std::cout << "         l1       l2" << endl;
 //   std::cout << "                 answer1      answer1";
    cout << "  " << "  " << endl << endl;

    cout << fixed << setprecision(6);

double sum = 0.0;

 for (int i=1; i<floor(tt)+1; i++ ){
    sum +=  pow(k,i)*series(i,t);
//    cout << setw(12) << i << setw(13) << series(i,t) << setw(13) << pow(k,i) <<setw(13) << series(i,t)*pow(k,i)<< setw(13)<< sum;
    cout << setw(12) << i << setw(13) << series(i,t) << setw(13) << setw(13)<< sum;
    cout << endl;
 }

    return 0; 
} 

/* 
leanne@leanne-HP-ProBook-450-G5:~/explicit-algorithm-volterra$ ./testh
 Enter the value for t: 0.8
 Enter the value for T (T>=1): 7.3
 Enter the value for k: 0.7
           n     gamma_n       h_n    

           1     1.000000     0.700000
           2     0.800000     1.092000
           3     0.320000     1.201760
           4     0.085333     1.222249
           5     0.017067     1.225117
           6     0.002731     1.225438
           7     0.000364     1.225468

*/