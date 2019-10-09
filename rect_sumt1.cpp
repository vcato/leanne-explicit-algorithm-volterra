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

  
// Driver code 
int main() 
{ 
 double t; int nn;
 double h;
 //h = static_cast<float>(t)/nn;
    cout <<" Enter the value for t: ";
    cin >> t;
    cout <<" Enter the value for n (n>=1): ";
    cin >> n;
    cout <<" Enter the value for nn: ";
    cin >> nn;
    h= t/nn;
 for (int i=1; i<nn; i++ ){
    cout << setw(12) << i << setw(13) << h*i;//<< setw(13) << series(nn,t);
    cout << setw(12);
    series(n,h*i);
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

As we can see,  from both sides, \phi_n converges to 0 quite fast, 
especially when 0<=t <1.
Reason:
The \phi_n(t) are functions which are zero for t >= n.  
The functions are symmetric about t=n/2 where these functions attain a maximum.
so the biggest possible values of g_n are for t close to t=n/2. So for any 0 <= t < 1, 
one would expect \phi_n(t) goes to zero for large n.
*/

/* leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ ./test1
 Enter the value for t: 2.2
 Enter the value for n (n>=1): 4
 Enter the value for nn: 40
           1        0.055 2.77292e-05
           2         0.11 0.000221833
           3        0.165 0.000748688
           4         0.22  0.00177467
           5        0.275  0.00346615
           6         0.33   0.0059895
           7        0.385   0.0095111
           8         0.44   0.0141973
           9        0.495   0.0202146
          10         0.55   0.0277292
          11        0.605   0.0369075
          12         0.66    0.047916
          13        0.715    0.060921
          14         0.77   0.0760888
          15        0.825   0.0935859
          16         0.88    0.113579
          17        0.935    0.136233
          18         0.99    0.161717
          19        1.045    0.190134
          20          1.1    0.221167
          21        1.155    0.254317
          22         1.21    0.289086
          23        1.265    0.324974
          24         1.32    0.361483
          25        1.375    0.398112
          26         1.43    0.434363
          27        1.485    0.469737
          28         1.54    0.503735
          29        1.595    0.535857
          30         1.65    0.565604
          31        1.705    0.592478
          32         1.76    0.615979
          33        1.815    0.635607
          34         1.87    0.650865
          35        1.925    0.661253
          36         1.98    0.666271
          37        2.035    0.665463
          38         2.09    0.658931
          39        2.145    0.647166
*/