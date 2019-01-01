#include <iostream>
#include <vector>

using std::cout;
using std::endl;

class Array
{
private:
    int     L;     // Laenge
    double* feld;  // Daten

public:
    Array( int size= 0)         // Konstruktor
    {
        L= size;
        feld= new double[size];

        for (int i=0; i<L; ++i)
            feld[i]= 0;
    }

    Array( const Array& a)   // Kopierkonstruktor
      : L( a.size()), feld(new double[L]) // Init.liste
    {
        for (int i=0; i<L; ++i)
            feld[i]= a.feld[i];
    }

    ~Array()                 // Destruktor
    {
        delete[] feld;
    }

    Array& operator=( const Array& r)
    {
        resize( r.size());
        for (int i=0; i<L; ++i)
            feld[i]= r.feld[i];
        return *this;
    }

    int size() const { return L; }
    void resize( int size)
    {
        double *neu= new double[size];

        for (int i=0; i<size; ++i)
            if (i<L)
                neu[i]= feld[i];
            else
                neu[i]= 0;

        L= size;
        delete[] feld;
        feld= neu;
    }

    double& operator[] (int i)      // (a) schreiben/lesen
    {
        cout << "Zugriff mit Variante (a)" << endl;
        return feld[i];
    }

    double operator[] (int i) const // (b) nur lesen
    {
        cout << "Zugriff mit Variante (b)" << endl;
        return feld[i];
    }
};


int main()
{
    Array A;        // Array A; nicht erlaubt, da es keinen Default-Konst. gibt
    Array B(7);        // konstr. Array der Laenge 7
    B[1]= 1.3;         // Schreibzugriff mit (a)
    A= B;              // Zuweisungsop. von Array

    const Array C= B;  // Kopierkonstruktor
    cout << C[1] << endl; // Lesezugriff mit (b), da C konstant
    cout << B[1] << endl; // Lesezugriff mit (a)

    return 0;
}
