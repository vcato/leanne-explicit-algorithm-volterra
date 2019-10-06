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
    double sum = 0.0;

// loop to display the series
    for (int i=0; i<n+1; i++) {

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
 int n, r; double t;

    cout <<" Enter the value for n (n>=1): ";
    cin >> n;
    cout <<" Enter the value for t : ";
    cin >> t;
    series(n,t);
    cout << endl;
 //   cout << series(n, t) << endl;
/* be careful, you cannot implement above as Here, 
series is a function that returns void, meaning that it doesn't evaluate to a value. The code you've written is then trying to apply operator << to a nonexistent value and endl, 
which is impossible because you can't apply any operators to a void value.*/
    return 0; 
} 

/* leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ g++ -o rects rect_sum.cpp
leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ ./rects
 Enter the value for n (n>=1): 1
 Enter the value for t : 2
0
leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ ./rects
 Enter the value for n (n>=1): 1
 Enter the value for t : 0.1
1
leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ ./rects
 Enter the value for n (n>=1): 1
 Enter the value for t : 0.01
1
leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ ./rects
 Enter the value for n (n>=1): 1
 Enter the value for t : 0.4
1
leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ ./rects
 Enter the value for n (n>=1): 1
 Enter the value for t : 0.9
1
leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ ./rects
 Enter the value for n (n>=1): 1
 Enter the value for t : 0.99
1
leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ ./rects
 Enter the value for n (n>=1): 1
 Enter the value for t : 1.01
0
leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ ./rects
 Enter the value for n (n>=1): 2
 Enter the value for t : 0.2
0.2
leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ ./rects
 Enter the value for n (n>=1): 2
 Enter the value for t : 1
1
leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ ./rects
 Enter the value for n (n>=1): 2
 Enter the value for t : 1.5
0.5
leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ ./rects
 Enter the value for n (n>=1): 2
 Enter the value for t : 2
0
leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ ./rects
 Enter the value for n (n>=1): 3
 Enter the value for t : 0.2
0.02
leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ ./rects
 Enter the value for n (n>=1): 3
 Enter the value for t : 0.5
0.125
leanne@leanne-Latitude-5480:~/explicit-algorithm-volterra$ ./rects
 Enter the value for n (n>=1): 3
 Enter the value for t : 1.5
0.75
*/