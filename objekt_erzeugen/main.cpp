#include <string>
#include <iostream>
using namespace std;

class postenTyp
{
private:
    int anzahl = 0;
    double preis = 0.0;
    std::string bezeichung = "unbekannt";
public:
    postenTyp(){};
    postenTyp(const int&, const double&, const std::string&);
    postenTyp(const postenTyp&);
    postenTyp& operator = (const postenTyp&);
    void ausgeben();
};

postenTyp::postenTyp(const postenTyp& p)
{
    *this = p;
}

postenTyp::postenTyp(const int& a, const double& p, const std::string& b) {
    anzahl = a;
    preis = p;
    bezeichung = b;
}

postenTyp& postenTyp::operator = (const postenTyp& p) {
    if(p.anzahl <= 0)
        anzahl = 0;
    else
        anzahl = p.anzahl;

    if(p.preis < 0.1)
        preis = 0;
    else
        preis = p.preis;

    if(p.bezeichung == "")
        bezeichung = "unbekannt";
    else
        bezeichung = p.bezeichung;

    return *this;
}

void postenTyp::ausgeben() {
    std::cout << anzahl << " " << preis << " " << bezeichung << '\n';
}

int main()
{
    postenTyp pEins{4, 1.15, "Mango"};
    pEins.ausgeben();

    postenTyp pZwei{pEins};
    pZwei.ausgeben();

    postenTyp pDrei;
    pDrei.ausgeben();
    pDrei = pZwei;
    pDrei.ausgeben();

}
