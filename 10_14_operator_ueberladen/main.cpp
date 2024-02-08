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
    void ausgeben();

    postenTyp operator + (const int&);
    postenTyp operator + (const std::string&);
    bool operator > (const postenTyp&);
};

postenTyp::postenTyp()
{
    anzahl = 0;
    preis = 0.0;
    bezeichnung = "";
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
        bezeichnung = "Unbekannt";
    else
        bezeichnung = b;
}

void postenTyp::ausgeben()
{
    std::cout << anzahl << " " << preis << " " << bezeichnung << '\n';
}

postenTyp postenTyp::operator + (const int& anzahlHinzu)
{
    postenTyp pTemp = *this;
    if(anzahl + anzahlHinzu < 0)
        pTemp.anzahl = 0;
    else
        pTemp.anzahl += anzahlHinzu;
    return pTemp;
}

postenTyp postenTyp::operator + (const std::string& textHinzu)
{
    postenTyp pTemp = *this;
    pTemp.bezeichnung += ", " + textHinzu;
    return pTemp;
}

bool postenTyp::postenTyp::operator>(const postenTyp& anderesObjekt)
{
    if(anzahl * preis > anderesObjekt.preis * anderesObjekt.anzahl)
        return true;
    else
        return false;
}


int main()
{
    postenTyp pEins{5, 15, "Banane"};
    postenTyp pZwei;

    pZwei = pEins + 7;
    pEins.ausgeben();
    pZwei.ausgeben();

    pEins = pEins + 4;
    pEins.ausgeben();

    pEins = pEins + " Bio";
    pEins.ausgeben();

    postenTyp pDrei{5, 0.75, "Kiwi"};
    pDrei.ausgeben();

    if(pEins > pDrei)
        std::cout << " pEins ist größer als pDrei" << '\n';
    else
        std::cout << " pEins ist kleiner oder gleich als pDrei" << '\n';
    (pEins + 2).ausgeben();
}
