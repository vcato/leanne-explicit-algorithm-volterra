#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 
  
int fact(int n); 
  
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

double my_fct(double t, double a, int k){
    return (t>= a ? pow(t-a, k) : 0);
}

void series(int n, double t){

// calculating the value of (n-1)!

    int n1fact = fact(n-1);
//    double sum = 0.0;

// loop to display the series
    for (int i=0; i<n+1; i++) {

        int mPow = pow(-1,i);
        int comb = nCr(n, i);
        double myfct = my_fct(t,i,n-1);
        //    cout <<  myfct << " ";
        //    return mPow * comb * myfct / n1fact;
        //sum += (mPow * comb * myfct) / n1fact;
        cout << mPow * comb * myfct / n1fact << " ";
    }
}

  
// Driver code 
int main() 
{
    int n, r; double t;

    cout <<" Enter the value for n (n>=1): ";
    cin >> n;
    cout <<" Enter the value for t : ";
    cin >> t;

  //  double n = 8, r = 2, t = 9.2; 
 //   cout << nCr(n, r) << endl; 
 //   cout << rect(0.2,0.1,0.9) << endl;
 //   cout << impul(0.0) << endl;
 //   cout << my_fct(1.2,0.9, 3) << endl;
    series(n, t);
    cout << endl;
/* be careful, you cannot implement above as cout << "The terms of our series are" << series(n, t) << endl;, 
series is a function that returns void, meaning that it doesn't evaluate to a value. The code you've written is then trying to apply operator << to a nonexistent value and endl, 
which is impossible because you can't apply any operators to a void value.*/
    return 0; 
} 