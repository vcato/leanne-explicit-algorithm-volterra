#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 


// Global Declaration Section
int n, r, a, k, i; double t, low, up;

 
 // Function Declaration  
int nCr(int n, int r);
int fact(int n); 
double rect(double t, double low, double up);
double impul(double t);
double my_fct(double t, int a, int k);
void series(int n, double t);
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

void series(int n, double t){

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
    cout << sum;
}

void max_ser(int n, double t){
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
    cout << sum/2;
}
  
// Driver code 
int main() 
{ 
 int n = 11, r; double t;

  //  cout <<" Enter the value for n (n>=1): ";
  //  cin >> n;
    cout <<" Enter the value for t : ";
    cin >> t;
 for (int nn=1; nn<n; nn++ ){
    cout << setw(12) << nn << setw(13);//<< setw(13) << series(nn,t);
    series(nn,t);
    cout << setw(12);
    max_ser(nn,t);
    cout << endl;
 }
    return 0; 
} 

/*
leanne@leanne-HP-ProBook-450-G5:~/explicit-algorithm-volterra$ ./test
 Enter the value for t : 1.2
           1            0           0
           2          0.8         0.4
           3         0.66        0.33
           4     0.282667    0.141333
           5    0.0860667   0.0430333
           6      0.02072     0.01036
           7   0.00414658  0.00207329
           8  0.000710928 0.000355464
           9  0.000106642 5.33209e-05
          10   1.4219e-05 7.10948e-06
leanne@leanne-HP-ProBook-450-G5:~/explicit-algorithm-volterra$ ./test
 Enter the value for t : 0.8
           1            1         0.5
           2          0.8         0.4
           3         0.32        0.16
           4    0.0853333   0.0426667
           5    0.0170667  0.00853333
           6   0.00273067  0.00136533
           7  0.000364089 0.000182044
           8  4.16102e-05 2.08051e-05
           9  4.16102e-06 2.08051e-06
          10  3.69868e-07 1.84934e-07

As we can see,  from both sides, g_n converges to 0 quite fast, 
especially when 0<=t <1.
Reason:
The g_n(t) are functions which are zero for t >= n.  
The functions are symmetric about t=n/2 where these functions attain a maximum.
so the biggest possible values of g_n are for t close to t=n/2. So for any 0 <= t < 1, 
one would expect g_n(t) goes to zero for large n.
*/