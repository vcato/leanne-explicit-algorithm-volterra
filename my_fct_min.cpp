#include <iostream>
//#include <fstream>
//#include <string>
#include <cmath>
using namespace std;
void slfit()
{
	float x[20],y[20],den,a,b,smx,smx2,smy,smxy;
	int n,i;
	char choice;
	cout << "For default values enter 'y' else 'n'\n";
	cin >> choice;
	if (choice == 'y')
	{
		n = 5;
		x[1] = 1; y[1] = 3;
		x[2] = 2; y[2] = 4;
		x[3] = 3; y[4] = 6;
		x[5] = 5; y[5] = 8;
	}
	else
	{
		cout << "input the no. of data points, n\n";
		cin >> n;
		cout << "input the data points, xi yi\n";
		for (i = 1; i<=n; i++)
			{
				cout << "x["<<i<<"]=";
				cin >> x[i];
				cout << "y["<<i<<"]=";
				cin >> y[i];
			}
	}
	smx2 = 0; smx = 0; smy = 0; smxy = 0;
	for (i=1; i<=n; i++)
	{
		smx += x[i];
		smy += y[i];
		smx2 += x[i]*x[i];
		smxy += x[i]*y[i];
	}
	den = n*smx2-smx*smx;
	b = (n*smxy-smx*smy)/den;
	a = (smy - b*smx)/n;
	cout << "values of coefficients a and b is \n";
	cout << "a=" <<a<<endl;
	cout << "b=" <<b<<endl;
	cout << "y="<<a<<"+"<<b<<"x"<<"is the regression line"<<endl;
}

int main()
{
	/* code */
	slfit();
}
