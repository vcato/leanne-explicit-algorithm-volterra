#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

double
fitfunction(double a, double b, double c, double d, double x, double y)
{
    double fct = a + b * x + c * y + d * y * y;
    return fct;
}

double
chisquarecalculation(double a, double b, double c, double d, double x, double y, double z)
{
    double fit = fitfunction(a, b, c, d, x, y);
    double chisquare = ((z - fit) * (z -fit)) / (z * z);
    return chisquare;

}

void inAndOut(const char *inFileName, const char *outFileName)
{
    ifstream input(inFileName);
    ofstream output(outFileName);

    //definition of the chisquares function as a function of a,b,c,d
    double a = 1;       //fit parameters which I would like to use as theoretical entities, uninitialized
    double b = 1;
    double c = 1;
    double d = 1;
    double x, y, z;

    double sum(0.);

    while (input >> x >> y >> z) {
    double chi = chisquarecalculation(a, b, c, d, x, y, z);
    output << chi << " " << endl;
    sum += chi;
    }
    cout << "chisquare for " << inFileName << " dataset by direct method: " << sum << endl;
}


int
main()
{
    inAndOut("dataset1_usedtofit.txt", "chisquare1.txt");
    inAndOut("dataset2_usedtofit.txt", "chisquare2.txt");
    inAndOut("dataset3_usedtofit.txt", "chisquare3.txt");
    inAndOut("dataset4firstpart_usedtofit.txt", "chisquare4.txt");
    inAndOut("dataset4secondpart_usedtofit.txt", "chisquare5.txt");
    inAndOut("dataset4thirdpart_usedtofit.txt", "chisquare6.txt");
    inAndOut("dataset4lastpart_usedtofit.txt", "chisquare7.txt");
}