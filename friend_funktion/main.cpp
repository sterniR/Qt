#include <iostream>
#include <string>
using namespace std;

class postenTyp {
    friend double preisGesamt(const postenTyp& p);

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

double preisGesamt(const postenTyp& p) {
    return p.anzahl * p.preis;
}

int main()
{
    postenTyp pEins{4, 1.15, "Mango"};
    pEins.ausgeben();
    std::cout << "Gesamtpreis: " << preisGesamt(pEins) << '\n';
}
