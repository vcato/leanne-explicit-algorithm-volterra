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
 int n = 11, r; double t;

  //  cout <<" Enter the value for n (n>=1): ";
  //  cin >> n;
    cout <<" Enter the value for t : ";
    cin >> t;
 for (int nn=1; nn<n; nn++ ){
    cout << setw(12) << nn << setw(13);//<< setw(13) << series(nn,t);
    series(nn,t);
    cout << endl;
 }
    return 0; 
} 

/* leanne@leanne-HP-ProBook-450-G5:~/explicit-algorithm-volterra$ ./rects
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
leanne@leanne-HP-ProBook-450-G5:~/explicit-algorithm-volterra$ ./rects
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
leanne@leanne-HP-ProBook-450-G5:~/explicit-algorithm-volterra$ 
*/