#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::istream;
using std::ostream;
using std::string;
using std::vector;
using std::list;

struct Datum
{
  // ...
};

struct Person
{
  // ...
};

// Typ AdressbuchT und GebListeT definieren:
typedef //...


void Datum_schreiben(ostream& out, const Datum& datum)
{
    out << datum.Tag << "." << datum.Monat << "."
        << datum.Jahr;
}

void Person_schreiben(ostream& out, const Person& person)
{
    out << person.Nachname << " " << person.Vorname << " "
        << person.Email << " " << person.MatNr << " ";
    Datum_schreiben( out, person.Geburtstag);
}

void AB_schreiben(ostream& out, const AdressbuchT& AB)
{
    for (int i= 0; i < AB.size(); i++) 
    {
        Person_schreiben( out, AB[i]);
        out << "\n";
    }
}

void Datum_lesen(istream& in, Datum& datum)
{
}

void Person_lesen(istream& in, Person& person)
{
}

void AB_lesen(istream& in, AdressbuchT& AB)
{
    do 
    {
        // ... 
    } while (!in.eof());
}

void geboren_in(int Monat, const AdressbuchT& AB, AdressbuchT& MonatAB)
{
}

int main()
{
    AdressbuchT AB;
    AB_lesen(...);
    cout << "Das Adressbuch hat " << AB.size() << " Eintraege:\n";
    AB_schreiben( cout, AB);
    // ...
    return 0;
}

