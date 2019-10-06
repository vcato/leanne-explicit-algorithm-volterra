// CPP program to print terms of binomial  
// series and also calculate sum of series. 
#include <bits/stdc++.h> 
using namespace std; 
  
// function to calculate factorial of  
// a number 
int factorial(int n) 
{ 
    int f = 1; 
    for (int i = 2; i <= n; i++) 
        f *= i;         
    return f; 
} 
  
// fuction to print the series 
void series(int A, int X, int n) 
{      
    // calculating the value of n! 
    int nFact = factorial(n); 
  
    // loop to display the series 
    for (int i = 0; i < n + 1; i++) { 
          
        // For calculating the  
        // value of nCr 
        int niFact = factorial(n - i); 
        int iFact = factorial(i); 
  
        // calculating the value of  
        // A to the power k and X to 
        // the power k 
        int aPow = pow(A, n - i); 
        int xPow = pow(X, i); 
  
        // display the series 
        cout << (nFact * aPow * xPow) / 
                 (niFact * iFact) << " "; 
    } 
} 
  
// main fuction started 
int main() 
{ 
    int A = 3, X = 4, n = 5; 
    series(A, X, n); 
    return 0; 
} 