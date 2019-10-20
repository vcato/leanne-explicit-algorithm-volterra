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

    cout  << "           N          n       kernel_n     gamma_n      h_n";
 //   std::cout << "         l1       l2" << endl;
 //   std::cout << "                 answer1      answer1";
    cout << "  " << "  " << endl << endl;

    cout << fixed << setprecision(6);

double sum = 0.0;

for (int i=0; i<n; i++){
  for (int j=1; j<nn+1; j++){
    sum += pow(kernel(i,k,theta,c,del),j)* series(i,t-i);
    cout << setw(12) << j << setw(12) << i << setw(13) << pow(kernel(i,k,theta,c,del),j) << setw(12) << series(i,t-i) << setw(13) << setw(13)<< sum;
    cout << endl;
  }
}
return 0;
}



/* 
 Enter the value for t: 3.5
 Enter the value for n (n>=0): 4
 Enter the value for N (N>=1): 3
 Enter the value for k: 0.4
 Enter the value for theta: 0.9
 Enter the value for c: 1.1
 Enter the value for delta: 0.01
           N          n       kernel_n     gamma_n      h_n    

           1           0     0.327273    0.285714     0.093506
           2           0     0.107107    0.285714     0.124109
           3           0     0.035053    0.285714     0.134124
           1           1     0.321693    0.000000     0.134124
           2           1     0.103487    0.000000     0.134124
           3           1     0.033291    0.000000     0.134124
           1           2     0.316258    0.500000     0.292253
           2           2     0.100019    0.500000     0.342263
           3           2     0.031632    0.500000     0.358078
           1           3     0.310962    0.125000     0.396949
           2           3     0.096697    0.125000     0.409036
           3           3     0.030069    0.125000     0.412794

*/