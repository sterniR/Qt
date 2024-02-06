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
}
postenTyp::postenTyp(const int& a, const double& p, const std::string& b)
{
    anzahlPosten++;
    std::cout << "Konstruktor, Anzahl: " << anzahlPosten << '\n';
}
postenTyp::~postenTyp()
{
    anzahlPosten++;
    std::cout << "Destruktor, Anzahl: " << anzahlPosten << '\n';
}

void postenTyp::ausgeben()
{
    std::cout << "Statische Methode, Anzahl: " << anzahlPosten << '\n';
}

