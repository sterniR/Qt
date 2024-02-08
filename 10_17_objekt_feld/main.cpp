#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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
};

postenTyp::postenTyp()
{
    anzahl = 0;
    preis = 0.0;
    bezeichnung = "unbekannt";
}

postenTyp::postenTyp(const int& a, const double& p, const std::string& b)
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

postenTyp::~postenTyp()
{
    std::cout << "Destruktor: ";
    ausgeben();
}

void postenTyp::ausgeben()
{
    std::cout << anzahl << " " << preis << " " << bezeichnung << '\n';
}

int main()
{
    std::cout << "Feld erzeugen: " << '\n';
    std::vector<postenTyp> pFeld =
    {
        {4, 1.15, "Mango"},
        {7, 0.85, "Birne"}
    };
    std::cout << '\n';

    std::cout << "Feld erweitern mit resize(): " << '\n';

    pFeld.resize(3);
    std::cout << '\n';

    std::cout << "Element zuweisen: " << '\n';
    pFeld.at(2) = {8, 1.75, "Ananas"};
    std::cout << '\n';

    std::cout << "Feld erweitern mit push_back(): " << '\n';
    pFeld.push_back({2, 0.65, "Orange"});
    std::cout << '\n';

    std::cout << "Feld ausgeben: " << '\n';
    for(postenTyp &p : pFeld)
        p.ausgeben();
    std::cout << '\n';

}
