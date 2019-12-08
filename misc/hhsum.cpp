#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std; 


// Global Declaration Section
int r, a, k, n, nn; double t, theta, c, sig, low, up, del;
std::string base;
 
 // Function Declaration  
int nCr(int n, int r);
int fact(int n); 
double rect(double t, double low, double up);
double impul(double t);
double my_fct(double t, double a, double k);
double series(int n, double t);
double kernel(int n, double k, double t, double theta, double c, double sig, double del, string& base);
double findError(double h1,double h2);
void norms(double* x, int n, double& norm1, double& norminf);

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

double kernel(int n, double k, double t, double theta, double c, double sig, double del, string& base){
  if(base== "PL"){
    return k*theta*pow(c,theta)/(pow((c+(n+1)*del),(1+theta)));
  }
  else if (base=="Exp"){
    return k*theta*exp(-theta*t);
  }
  else if (base=="RL"){
    //(k*t/(sig*sig))*exp(-t*t/(2*sig*sig));
    return (k*t/(pow(sig,2)))*exp(-t*t/(2*pow(sig,2)));
  }
//  return 0;
}

void norms(double* x, int n, double& norm1, double& norminf)
{
  norm1 = fabs(x[0]);
  norminf = norm1;
  for(int i=1; i<n; i++)
  {
    x[i] = fabs(x[i]);
    norm1 += x[i];
    if(x[i]> norminf)
      norminf = x[i]; 
  }
}

double findError(double h1,double h2)
{
  return fabs(h1-h2);
 }

  
// Driver code 
int main() 
{

  int n, nn;
  double k, t, theta, c, sig, del;
  std::string base;

  cout <<" Enter kernel: ";
  getline (cin, base);
  cout <<" Enter the value for t: ";
  cin >> t;
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
  cout <<" Enter the value for sigma (>=1): ";
  cin >> sig; 
  cout <<" Enter the value for delta: ";
  cin >> del;

  double* x = new double[n];
  x[0]=-5.1; x[1]=2.3; x[2]=3.7; x[3]=1.1; x[4]=0.7;
  double norm1;
  double norminf;
  norms(x,n,norm1,norminf);
  cout << "norm1 = " << norm1 << endl;
  cout << "norminf = " << norminf << endl;
  delete[] x;

  cout  << "           N          n       kernel_n     gamma_n      h_n          h           error";
  cout << "  " << "  " << endl << endl;

  cout << fixed << setprecision(6);
  double sum1 = 0.0;
  double sum2 = 0.0;


  for (int i=0; i<n; i++){
    for (int j=1; j<nn+1; j++){
      sum1 += pow(kernel(i,k,t,theta,c,sig,del,base),j)*series(i,t-i);
      sum2 += (1/del)*pow(kernel(i,k,t,theta,c,sig,del,base),j)*series(i,t*(1/del)-i);
      cout << setw(12) << j << setw(12) << i << setw(13) << pow(kernel(i,k,t,theta,c,sig,del,base),j) << setw(12) << series(i,t-i) << setw(13)<< sum1 << setw(13) << sum2 << setw(13) << findError(sum2,sum1);
      cout << endl;
    }
  }
  return 0;
  }

/* 
 Enter kernel: RL
 Enter the value for t: 3.5
 Enter the value for n (n>=0): 4
 Enter the value for N (N>=1): 3
 Enter the value for k: 0.8
 Enter the value for theta: 0.7
 Enter the value for c: 1.1
 Enter the value for sigma (>=1): 1
 Enter the value for delta: 0.01
norm1 = 12.2
norminf = 5.1
           N          n       kernel_n     gamma_n      h_n          h           error    

           1           0     0.006125    0.285714     0.001750     0.001750     0.000000
           2           0     0.000038    0.285714     0.001761     0.001761     0.000000
           3           0     0.000000    0.285714     0.001761     0.001761     0.000000
           1           1     0.006125    0.000000     0.001761     0.001761     0.000000
           2           1     0.000038    0.000000     0.001761     0.001761     0.000000
           3           1     0.000000    0.000000     0.001761     0.001761     0.000000
           1           2     0.006125    0.500000     0.004823     0.001761     0.003062
           2           2     0.000038    0.500000     0.004842     0.001761     0.003081
           3           2     0.000000    0.500000     0.004842     0.001761     0.003081
           1           3     0.006125    0.125000     0.005608     0.001761     0.003847
           2           3     0.000038    0.125000     0.005612     0.001761     0.003852
           3           3     0.000000    0.125000     0.005612     0.001761     0.003852

*/