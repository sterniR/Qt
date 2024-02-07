#include <iostream>
#include <string>

class postenTyp
{
private:
    int anzahl;
    double preis;
    std::string bezeichnung;
public:
    postenTyp();
    postenTyp(const int&, const double&, const std::string&);
    ~postenTyp();
    void ausgeben();

    static int anzahlPosten;
    static void ausgabeAnzahlPosten();
};

int postenTyp::anzahlPosten = 0;

postenTyp::postenTyp()
{
    anzahlPosten++;
    std::cout << "Konstruktor, Anzahl: " << anzahlPosten << '\n';

    anzahl = 0;
    preis = 0.0;
    bezeichnung = "unbekannt";
}

postenTyp::postenTyp(const int& a, const double& p, const std::string& b)
{
    anzahlPosten++;
    std::cout << "Konstruktor, Anzahl: " << anzahlPosten << '\n';

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

postenTyp::~postenTyp()
{
    anzahlPosten--;
    std::cout << "Destruktor, Anzahl: " << anzahlPosten << '\n';
}

void postenTyp::ausgeben()
{
    std::cout << anzahl << " " << preis << " " << bezeichnung << '\n';
}

void postenTyp::ausgabeAnzahlPosten()
{
    std::cout << "Statische Methode, Anzahl: " << anzahlPosten << '\n';
}

int main()
{
    postenTyp pEins{2, 1.45, "Apfel"};
    pEins.ausgeben();
    std::cout << "Anzahl: " << postenTyp::anzahlPosten << '\n';
    postenTyp::ausgabeAnzahlPosten();
    std::cout << '\n';

    postenTyp pZwei{5, 0.75, "Kiwi"};
    pZwei.ausgeben();
    std::cout << "Anzahl: " << postenTyp::anzahlPosten << '\n';
    postenTyp::ausgabeAnzahlPosten();
    std::cout << '\n';
}
