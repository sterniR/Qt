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
    bool operator > (const postenTyp&);
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
    //std::cout << "Destruktor: ";
    //ausgeben();
}

void postenTyp::ausgeben()
{
    std::cout << std::setw(2) << anzahl << " "
            << std::setw(5) << preis << " "
            << std::setw(5) << anzahl * preis << " "
            << bezeichnung << '\n';
}

bool postenTyp::operator>(const postenTyp& anderesObjekt)
{
    if(anzahl * preis > anderesObjekt.anzahl * anderesObjekt.preis)
        return true;
    else
        return false;
}

int main()
{
    std::vector<postenTyp> pFeld =
    {
        {7, 1.95, "Banane"},
        {5, 0.75, "Kiwi"}, {7, 0.85, "Birne"},
        {6, 2.1, "Mango"}, {3, 1.45, "Apfel"}
    };

    bool sortieren;

    do{
        sortieren = true;
        for(int i=0; i<pFeld.size()-1; i++)
        {
            if(pFeld.at(i) > pFeld.at(i+1))
            {
                sortieren = false;
                postenTyp p = pFeld.at(i);
                pFeld.at(i) = pFeld.at(i+1);
                pFeld.at(i+1) = p;
            }
        }
    }
    while(!sortieren);

    std::cout << std::fixed << std::setprecision(2);
    for(postenTyp &p : pFeld)
        p.ausgeben();

}
