#include <vector>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::vector;

// ----------------------------------------------------------------------
// Klasse Sudoku

class Sudoku
{
  private:
    vector<int> Data;     // Attribute

    void check( int& idx) const; // Index pruefen, evtl. korrigieren und
                                 // Fehlermeldung ausgeben
  public:
    Sudoku()
    {
        Data.resize(81);  // mit Nullen belegt
    }

    // Impliziter Destruktor ausreichend, da keine dyn. Speicherverwaltung.
    // Gleiches gilt fuer impliziten Kopierkonstr. und Zuweisungsoperator.

    // Zugriffsoperatoren
    int& operator() (int r, int c)
    {
        check(r); check(c);
        return Data[ (r-1)*9 + (c-1)];
    }

    int operator() (int r, int c) const
    {
        check(r); check(c);
        return Data[ (r-1)*9 + (c-1)];
    }

    // Methoden, die die Gueltigkeit pruefen
    bool validRow( int r) const;
    bool validCol( int c) const;
    bool validSqr( int a, int b) const;
    bool valid() const;

    bool solved() const
    { return getNumEmpty()==0 && valid(); }

    // Anzahl der leeren Felder
    int getNumEmpty() const;
};

// Ein-/Ausgabeoperatoren
ostream& operator<< (ostream& out, const Sudoku& S);

istream& operator>> (istream& in, Sudoku& S);


// ----------------------------------------------------------------------
// Klasse possibleDigits fuer Hilfszahlen


class possibleDigits
{
  private:
    vector<bool> possible;

  public:
    possibleDigits( bool setPossible= true)
    /*hier fehlt was*/
    { /*hier fehlt was*/ }

    int numPossible() const;

    bool isPossible( int digit) const { /*hier fehlt was*/ }
    void enable ( int digit) { /*hier fehlt was*/ }
    void disable( int digit) { /*hier fehlt was*/ }

    // Friend
    friend possibleDigits operator&&( const possibleDigits& a, const possibleDigits& b);
};

ostream& operator<<( ostream& out, const possibleDigits& a);

possibleDigits operator&&( const possibleDigits& a, const possibleDigits& b);


// ----------------------------------------------------------------------
// Klasse SudokuSolver

class SudokuSolver
{
  private:
    vector<possibleDigits> pdRow, pdCol, pdSqr;
    Sudoku&                Sudo;

    static int getSqr( int r, int c) { return 3*((r-1)/3) + (c-1)/3 + 1; }

  public:
    SudokuSolver( Sudoku& S);

    void setDigit  ( int r, int c, int digit);
    void unsetDigit( int r, int c);

    possibleDigits getPossible( int r, int c) const;

    void getNextCell( int& r_min, int& c_min) const;

    bool solve( int numEmpty);
};

