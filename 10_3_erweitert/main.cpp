#include <iostream>
#include <string>
#include <cmath>

class postenTyp
{
private:
    int anzahl;
    double preis;
    std::string bezeichnung;
public:
    void werteZuweisen(const int &, const double&, const std::string&);
    void mehrDavon(const int&);
    void rabattGeben(double);
    void ausgeben();
};

void postenTyp::werteZuweisen(const int &a, const double&p, const std::string&b)
{
    if(a < 0)
        anzahl = 0;
    else
        anzahl = a;

    if(p < 0)
        preis = 0.0;
    else
        preis = p;

    if(b == "")
        bezeichnung = "unbekannt";
    else
        bezeichnung = b;
}

void postenTyp::mehrDavon(const int &anzahlHinzu)
{
    if(anzahl + anzahlHinzu < 0)
        anzahl = 0;
    else
        anzahl += anzahlHinzu;
}

void postenTyp::rabattGeben(double rabattProzent)
{
    if(rabattProzent < 0)
        rabattProzent = 0;
    if(rabattProzent > 100)
        rabattProzent = 100;
    preis = preis * (1 - rabattProzent / 100);
    preis = round(preis * 100) / 100;
}

void postenTyp::ausgeben()
{
    std::cout << anzahl << " " << preis << " " << bezeichnung << '\n';
}


int main()
{
    postenTyp pEins;

    pEins.werteZuweisen(-5, -1.5, "");
    pEins.ausgeben();

    pEins.werteZuweisen(2, 1.45, "Apfel");
    pEins.ausgeben();

    pEins.mehrDavon(-6);
    pEins.ausgeben();

    pEins.mehrDavon(6);
    pEins.ausgeben();

    pEins.rabattGeben(-20);
    pEins.ausgeben();

    pEins.rabattGeben(10);
    pEins.ausgeben();

    pEins.rabattGeben(120);
    pEins.ausgeben();
}
