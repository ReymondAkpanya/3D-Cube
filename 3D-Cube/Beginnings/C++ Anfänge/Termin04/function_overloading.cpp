#include <iostream>
using namespace std;
//using std::cout;
//using std::endl;

void PrintSum( int x, int y)
{
    cout << "i-sum = " << x + y << endl;
}

void PrintSum( double x, double y)
{
    cout << "d-sum = " << x + y << endl;
}

void max( double a, double b)
{
    double maxi= a>b ? a : b;
    cout << "Das Maximum ist " << maxi << endl;
}

int main()
{
    max( 3, 4);     // ruft std::max fuer int auf
    PrintSum( 1, 3);     // Ausgabe "i-sum = 4"
    PrintSum( 1.7, 3.4); // Ausgabe "d-sum = 5.1"
    return 0;
}

