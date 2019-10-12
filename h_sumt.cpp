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
double h_series(int n, int k, double tt, double t);
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

double h_series(int n, int k, double tt, double t){
  double sum = 0.0;
  for ( n= 0; n < floor(tt)+1; n++) {
    double kPow = pow(k, n);
    double g_ser = series (n, t);
    sum +=  kPow*g_ser;
  }
  return sum;

}

  
// Driver code 
int main() 
{ 
 double t, tt; int nn;
 double h;
 //h = static_cast<float>(t)/nn;
    cout <<" Enter the value for t: ";
    cin >> t;
 //   cout <<" Enter the value for n (n>=1): ";
    cout <<" Enter the value for T (T>=1): ";
    cin >> tt;
    cout <<" Enter the value for k: ";
    cin >> k;
 for (int n=0; n<tt; n++ ){
    cout << setw(12) << n << setw(13) << series(n,t) << setw(13) << h_series(n,k,tt,t);
    //cout << setw(12);
    //series(n,h*i);
    cout << endl;
 }

    return 0; 
} 

/*
leanne@leanne-HP-ProBook-450-G5:~/explicit-algorithm-volterra$ ./test
 Enter the value for t : 1.2
           1            0  
           2          0.8  
           3         0.66       
           4     0.282667    
           5    0.0860667   
           6      0.02072     
           7   0.00414658 
           8  0.000710928 
           9  0.000106642 
          10   1.4219e-05 
leanne@leanne-HP-ProBook-450-G5:~/explicit-algorithm-volterra$ ./test
 Enter the value for t : 0.8
           1            1  
           2          0.8  
           3         0.32  
           4    0.0853333  
           5    0.0170667 
           6   0.00273067 
           7  0.000364089 
           8  4.16102e-05 
           9  4.16102e-06 
          10  3.69868e-07 

As we can see,  from both sides, \phi_n converges to 0 quite fast, 
especially when 0<=t <1.
Reason:
The \phi_n(t) are functions which are zero for t >= n.  
The functions are symmetric about t=n/2 where these functions attain a maximum.
so the biggest possible values of g_n are for t close to t=n/2. So for any 0 <= t < 1, 
one would expect \phi_n(t) goes to zero for large n. See the next block output. Fix n, discretize t.
*/

/*
leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ ./test
 Enter the value for t: 1.2
 Enter the value for n (n>=1): 2
 Enter the value for nn: 100
           1        0.012       0.012
           2        0.024       0.024
           3        0.036       0.036
           4        0.048       0.048
           5         0.06        0.06
           6        0.072       0.072
           7        0.084       0.084
           8        0.096       0.096
           9        0.108       0.108
          10         0.12        0.12
          11        0.132       0.132
          12        0.144       0.144
          13        0.156       0.156
          14        0.168       0.168
          15         0.18        0.18
          16        0.192       0.192
          17        0.204       0.204
          18        0.216       0.216
          19        0.228       0.228
          20         0.24        0.24
          21        0.252       0.252
          22        0.264       0.264
          23        0.276       0.276
          24        0.288       0.288
          25          0.3         0.3
          26        0.312       0.312
          27        0.324       0.324
          28        0.336       0.336
          29        0.348       0.348
          30         0.36        0.36
          31        0.372       0.372
          32        0.384       0.384
          33        0.396       0.396
          34        0.408       0.408
          35         0.42        0.42
          36        0.432       0.432
          37        0.444       0.444
          38        0.456       0.456
          39        0.468       0.468
          40         0.48        0.48
          41        0.492       0.492
          42        0.504       0.504
          43        0.516       0.516
          44        0.528       0.528
          45         0.54        0.54
          46        0.552       0.552
          47        0.564       0.564
          48        0.576       0.576
          49        0.588       0.588
          50          0.6         0.6
          51        0.612       0.612
          52        0.624       0.624
          53        0.636       0.636
          54        0.648       0.648
          55         0.66        0.66
          56        0.672       0.672
          57        0.684       0.684
          58        0.696       0.696
          59        0.708       0.708
          60         0.72        0.72
          61        0.732       0.732
          62        0.744       0.744
          63        0.756       0.756
          64        0.768       0.768
          65         0.78        0.78
          66        0.792       0.792
          67        0.804       0.804
          68        0.816       0.816
          69        0.828       0.828
          70         0.84        0.84
          71        0.852       0.852
          72        0.864       0.864
          73        0.876       0.876
          74        0.888       0.888
          75          0.9         0.9
          76        0.912       0.912
          77        0.924       0.924
          78        0.936       0.936
          79        0.948       0.948
          80         0.96        0.96
          81        0.972       0.972
          82        0.984       0.984
          83        0.996       0.996
          84        1.008       0.992
          85         1.02        0.98
          86        1.032       0.968
          87        1.044       0.956
          88        1.056       0.944
          89        1.068       0.932
          90         1.08        0.92
          91        1.092       0.908
          92        1.104       0.896
          93        1.116       0.884
          94        1.128       0.872
          95         1.14        0.86
          96        1.152       0.848
          97        1.164       0.836
          98        1.176       0.824
          99        1.188       0.812
*/