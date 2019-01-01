#include "sudoku.h"

// ----------------------------------------------------------------------
// Klasse Sudoku


// Ein-/Ausgabeoperatoren
ostream& operator<< (ostream& out, const Sudoku& S)
{
    for (int r=1; r<=9; ++r) {
        for (int c=1; c<=9; ++c) {
            const int z= S(r,c);
            if (z==0)
                out << ". ";
            else
                out << z << ' ';
        }
        out << endl;
    }
    return out;
}

istream& operator>> (istream& in, Sudoku& S)
{
    for (int r=1; r<=9; ++r)
        for (int c=1; c<=9; ++c)
            in >> S(r,c);
    return in;
}

// Sudoku-Methoden

void Sudoku::check( int& idx) const
{
    if (idx < 1) {
        cout << "Index " << idx << " ist ungueltig." << endl;
        idx= 1;
    }
    if (idx > 9) {
        cout << "Index " << idx << " ist ungueltig." << endl;
        idx= 9;
    }
}

int Sudoku::getNumEmpty() const
{
    int numEmpty= 0;
    for (int i=0; i<81; ++i)
        if (Data[i]==0)
            ++numEmpty;
        return numEmpty;
}

bool Sudoku::validRow( int r) const
{
    int haeufigkeit[10]= {}; // mit Nullen initialisiert

    for (int c=1; c<=9; ++c) {
        int z= (*this)(r,c);
        if (z != 0) {
            haeufigkeit[z]++;
            if (haeufigkeit[z] > 1) // z kommt mehr als einmal vor
                return false;
        }
    }
    return true;
}

bool Sudoku::validCol( int c) const
{
    int haeufigkeit[10]= {}; // mit Nullen initialisiert

    for (int r=1; r<=9; ++r) {
        int z= (*this)(r,c);
        if (z != 0) {
            haeufigkeit[z]++;
            if (haeufigkeit[z] > 1)
                return false;
        }
    }
    return true;
}

bool Sudoku::validSqr( int a, int b) const
{
    int haeufigkeit[10]= {}; // mit Nullen initialisiert
    // Eintrag oben links ist (r,c)
    const int r= 3*(a-1)+1, c= 3*(b-1)+1;

    for (int i=0; i<3; ++i) {
      for (int j=0; j<3; ++j) {
        int z= (*this)(r+i,c+j);
        if (z != 0) {
            haeufigkeit[z]++;
            if (haeufigkeit[z] > 1)
                return false;
        }
      }
    }
    return true;
}

bool Sudoku::valid() const
{
    bool val= true;

    for (int i=1; i<=9; ++i) {
        val= val && validRow(i)
                 && validCol(i);
    }
    for (int i=1; i<=3; ++i)
        for (int j=1; j<=3; ++j)
            val= val && validSqr( i, j);

    return val;
}


// ----------------------------------------------------------------------
// Klasse possibleDigits fuer die Hilfszahlen

ostream& operator<<( ostream& out, const possibleDigits& a)
{
    /*hier fehlt was*/
}

possibleDigits operator&&( const possibleDigits& a, const possibleDigits& b)
{
    /*hier fehlt was*/
}

// possibleDigits-Methoden

int possibleDigits::numPossible() const
{
    /*hier fehlt was*/
}


// ----------------------------------------------------------------------
// Klasse SudokuSolver

SudokuSolver::SudokuSolver( Sudoku& S)
 : /*hier fehlt was*/ Sudo(S)
{
    /*hier fehlt was*/
}

void SudokuSolver::setDigit( int r, int c, int digit)
{
    /*hier fehlt was*/
}

void SudokuSolver::unsetDigit( int r, int c)
{
    /*hier fehlt was*/
}

possibleDigits SudokuSolver::getPossible( int r, int c) const
{
    /*hier fehlt was*/
}

void SudokuSolver::getNextCell( int& r_min, int& c_min) const
{
    /*hier fehlt was*/
}

bool SudokuSolver::solve( int numEmpty)
{
    /*hier fehlt was*/
}

