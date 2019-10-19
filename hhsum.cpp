#include <bits/stdc++.h> 
#include <iostream>
#include <cmath>
using namespace std; 


// Global Declaration Section
int r, a, k; double t, low, up, del;

 
 // Function Declaration  
int nCr(int n, int r);
int fact(int n); 
double rect(double t, double low, double up);
double impul(double t);
double my_fct(double t, double a, double k);
double series(int n, double t);
double kernel(int n, double k, double theta, double c, double del);

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
    for ( int i=0; i<n+1; i++) {

        int mPow = pow(-1,i);
        int comb = nCr(n, i);
        double myfct = my_fct(t,i,n-1);
        //cout << mPow * comb * myfct / n1fact << " ";
        sum += mPow * comb * myfct/ n1fact;
    }
    return sum;
}

double kernel(int n, double k, double theta, double c, double del){
    return k*theta*pow(c,theta)/(pow((c+n*del),(1+theta)));
  //return k*theta*c*del*n;
}

  
// Driver code 
int main() 
{
int n, nn;
double t, k, theta, c, del; 
double h;
//double kernel;
 //h = static_cast<float>(t)/nn;
//cout << series(3,2);
//cout << "kernel is "<< kernel(3,1,0.8,1.2,0.01) << endl;

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

//cout << "kernel is "<< kernel(n,k,theta,c,del) << endl;

    cout  << "           n     gamma_n       h_n";
 //   std::cout << "         l1       l2" << endl;
 //   std::cout << "                 answer1      answer1";
    cout << "  " << "  " << endl << endl;

    cout << fixed << setprecision(6);

double sum = 0.0;

for (int i=0; i<n; i++){
  for (int j=1; j<nn+1; j++){
    sum += pow(kernel(i,k,theta,c,del),j)* series(i,t-i);
    cout << setw(12) << i << setw(13) << series(i,t-i) << setw(13) << setw(13)<< sum;
    cout << endl;
  }
}
return 0;
}



/* 
leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ ./hhs
 Enter the value for t: 3.5
 Enter the value for n (n>=0): 2
 Enter the value for N (N>=1): 5
 Enter the value for k: 9
 Enter the value for theta: 0.9
 Enter the value for c: 1.1
 Enter the value for delta: 0.001
           n     gamma_n       h_n    

           0     0.285714     2.103896
           0     0.285714    17.596222
           0     0.285714   131.676076
           0     0.285714   971.718637
           0     0.285714  7157.486590
           1     0.000000  7157.486590
           1     0.000000  7157.486590
           1     0.000000  7157.486590
           1     0.000000  7157.486590
           1     0.000000  7157.486590
leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ g++ -o hhs hhsum.cpp
leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ ./hhs
 Enter the value for t: 3.5
 Enter the value for n (n>=0): 4
 Enter the value for N (N>=1): 5
 Enter the value for k: 9
 Enter the value for theta: 0.9
 Enter the value for c: 1.1
 Enter the value for delta: 0.001
           n     gamma_n       h_n    

           0     0.285714     2.103896
           0     0.285714    17.596222
           0     0.285714   131.676076
           0     0.285714   971.718637
           0     0.285714  7157.486590
           1     0.000000  7157.486590
           1     0.000000  7157.486590
           1     0.000000  7157.486590
           1     0.000000  7157.486590
           1     0.000000  7157.486590
           2     0.500000  7161.155723
           2     0.500000  7188.080791
           2     0.500000  7385.664086
           2     0.500000  8835.582709
           2     0.500000 19475.470161
           3     0.125000 19476.385864
           3     0.125000 19483.093971
           3     0.125000 19532.235074
           3     0.125000 19892.224596
           3     0.125000 22529.374532


*/