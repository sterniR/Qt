#include <string>
#include <iostream>
using namespace std;

class postenTyp {
    friend class postenAktion;

private:
    int anzahl;
    double preis;
    std::string bezeichnung;
public:
    postenTyp(int, double, std::string);
    void ausgeben();
};

postenTyp::postenTyp(int a, double p, std::string b) {
    anzahl = a;
    preis = p;
    bezeichnung = b;
}

void postenTyp::ausgeben() {
    std::cout << anzahl << " " << preis << " " << bezeichnung << '\n';
}

class postenAktion {
public:
    static void anzahlVerdoppeln(postenTyp&);
    static void preisVerdoppeln(postenTyp&);

};

void postenAktion::anzahlVerdoppeln(postenTyp& p) {
    p.anzahl *= 2;
}

void postenAktion::preisVerdoppeln(postenTyp& p) {
    p.preis *= 2;
}

int main()
{
    postenTyp pEins{4,1.15,"Mango"};
    pEins.ausgeben();

    postenAktion::anzahlVerdoppeln(pEins);
    postenAktion::preisVerdoppeln(pEins);
    pEins.ausgeben();
}
