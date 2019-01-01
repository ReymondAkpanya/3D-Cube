#include <iostream>

using namespace std;

int main()
{
    double zahl[5]= {1,2}; // Feldeintraege mit 0 initialisieren
    int d= 47.11;
    cout << "zahl: " << zahl << endl;     // gibt Adresse aus (da zahl ein Zeiger ist)
    cout << "*zahl: " << (*zahl) << endl; // gibt Inhalt der Speicheradresse aus

    for (int i=0; i<10; ++i)
        cout << "zahl[" << i << "]: " << zahl[i] << endl;
    // Vorsicht: nur die Zugriffe zahl[0] bis zahl[4] greifen auf das Feld zu,
    // ab zahl[5] wird (unbemerkt) auf ungueltigen Speicher zugegriffen!

    cout << "d = " << d << endl;
    zahl[5]= 11.2;   // ungueltiger Zugriff, ueberschreibt d!
    cout << "d = " << d << endl;
    return 0;
}
