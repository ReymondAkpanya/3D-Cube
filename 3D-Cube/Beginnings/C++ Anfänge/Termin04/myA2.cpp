#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

double f( double x)
{
    return std::exp( std::sin (x)) - (x-1)*(x-6);
}

double MPRegel( double a, double b, int N)
{
    double h= (b-a)/N;
    double ergebnis= 0;

    for (int i=1; i<=N; ++i)
    {
        double xi= a + (i - 1.0/2)*h;
        ergebnis+= f(xi);
    }

    return h*ergebnis;
}

int main()
{
    cout << "a, b, N eingeben: " << endl;
    double a, b;
    int N;

    cin >> a >> b >> N;

    cout << "Integral ist etwa "
         << MPRegel( a, b, N) << endl;
    return 0;
}
