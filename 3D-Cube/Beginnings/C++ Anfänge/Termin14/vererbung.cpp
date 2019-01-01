#include <iostream>
#include <vector>

using namespace std;

class Form2D
// Klasse ist polymorph, da sie virtuelle Methoden besitzt
// und abstrakt, da sie rein virtuelle Methoden besitzt.
{
private:
    int farbe;
protected:
    double hoehe, breite;
public:
    Form2D( double h=0, double b=0)
    : hoehe(h), breite(b)
    { cout << "Form2D-Konstruktor!" << endl; }

    virtual ~Form2D() { cout << "Form2D-Destruktor" << endl;} // best practice fuer polymorphe Klassen

    void setzeGroesse( double h, double b)
    {
        hoehe= h; breite= b;
    }

    virtual double Flaeche() const = 0; // rein virtuell
};

class Rechteck: public Form2D
{
public:
    double Flaeche() const { return hoehe*breite; }
};

class Quadrat: public Rechteck
{
    public:
    double Flaeche() const { return 42; }
};

class Dreieck: public Form2D
{
    double winkel;
public:
    Dreieck( double h, double b, double w)
    : Form2D( h, b ), winkel(w)
    {
        cout << "Dreieck-Konstruktor" << endl;
    }
    ~Dreieck() { cout << "Dreieck-Destruktor" << endl;}
    double Flaeche() const { return hoehe*breite/2; }
};

class Kreis: public Form2D
// abstrakte Klasse, da die rein virtuelle Methode Flaeche nicht
// ueberladen ist und damit rein virtuell bleibt
{

};

int main()
{
//    Form2D f( 2, 3);
//    Kreis k;
    Dreieck d( 3, 4, 90);
    Rechteck r;
    r.setzeGroesse( 3, 4);
    Quadrat q;

    cout << "Flaeche von d = " << d.Flaeche() << endl;
    cout << "Flaeche von r = " << r.Flaeche() << endl;
    cout << "Flaeche von q = " << q.Flaeche() << endl;

    Form2D* fp= new Dreieck( 2,3,10);
    fp->setzeGroesse( 5, 2);
    cout << "Flaeche von *fp = " << fp->Flaeche() << endl;
//    Rechteck* qp= new Quadrat;
//    cout << "Flaeche von *qp = " << qp->Flaeche() << endl;


    delete fp;
    cout << "Und tschuess!" << endl;
    return 0;
}
