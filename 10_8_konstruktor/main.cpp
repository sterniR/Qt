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
    //(*this).ausgeben();
    //this->ausgeben();
}

void postenTyp::ausgeben()
{
    std::cout << anzahl << " " << preis << " " << bezeichnung << '\n';
}

int main()
{
    postenTyp pEins(2, 1.45, "Apfel");
    pEins.ausgeben();

    postenTyp pZwei{-5, -0.2, ""};
    pZwei.ausgeben();

    postenTyp pDrei;
    pDrei.ausgeben();

    pDrei = {7, 0.85, "Birne"};
    pDrei.ausgeben();
}
