#include <bits/stdc++.h> 
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
  
// Driver code 
int main() 
{ 
    int n = 5, r = 3; 
    cout << nCr(n, r) << endl; 
    cout << rect(0.2,0.1,0.9) << endl;
    cout << impul(0.0) << endl;
    return 0; 
} 