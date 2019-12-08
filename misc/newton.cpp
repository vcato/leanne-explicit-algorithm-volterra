// Newton Raphson


#include <iostream>
#include <conio.h>

using namespace std;

class solveNrMethod{
public:
    void getData()
    {
        cout << "Enter xi";
        cin >> xi;
    }

    double f(double x)
    {
        return x*x-3*x+2; // Change the equations for respective problem
    }

    double f2(double x)
    {
        return 2*x-3; // Find  the derivative for respective problem
    }

    double findError()
    {

        Error = (xi2-xi)/xi2;
        if(Error < 0)
            Error = -Error;
        return Error;

    }

    void calcxi2()
    {
        xi2 = xi - f(xi)/f2(xi);
    }

    void exchange()
    {
        xi = xi2;
    }

    void printTable(){
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(3);
        cout << xi << "\t" << f(xi)<< "\t" << f2(xi) << "\t"<< xi2 << "\t"<< Error <<endl;
    }

private:
    double xi,xi2,Error;

};

int main(){

 solveNrMethod no1;
 no1.getData();

    double e = 99;

    while(e >= 0.00009)
    {
        no1.calcxi2();
        e = no1.findError();
        no1.printTable();
        no1.exchange();
    }

 return 0;
}