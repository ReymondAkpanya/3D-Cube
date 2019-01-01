#include <iostream>
#include <fstream>

using namespace std;

void PrintStatus( istream& is)
{
    if (is.good())
        cout << "good ";
    if (is.fail())
        cout << "fail ";
    if (is.eof())
        cout << "eof ";
    cout << endl;
}

int main()
{
    ofstream out( "ausgabe.txt");
    out << "Hello world!\nHello Sven!";

    ifstream ifs( "input.txt");
    double d;
    int i;
    string s;
    ifs >> d >> i;
    PrintStatus( ifs);
    ifs >> i;
    PrintStatus( ifs);
    ifs.clear();
    PrintStatus( ifs);
    ifs >> s;
    PrintStatus( ifs);
    ifs >> s;
    PrintStatus( ifs);

    return 0;
}
