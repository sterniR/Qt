#include <iostream>
#include <string>

class postenTyp {
private:
    int anzahl;
    double preis;
    std::string bezeichnung;
public:
    postenTyp(const int&, const double&, const std::string&);
    bool operator > (const postenTyp&);
    void ausgeben();

};

postenTyp::postenTyp(const int& a, const double& p, const std::string& b) {
    anzahl = a;
    preis = p;
    bezeichnung = b;
}

void postenTyp::ausgeben() {
    std::cout << anzahl << " " << preis << " " << bezeichnung << '\n';
}

bool postenTyp::operator > (const postenTyp& p) {
    if(anzahl*preis > p.anzahl*p.preis)
        return true;
    else
        return false;
}

template <typename T>
T maximum(T& a, T& b)
{
    T ergebnis = b;
    if(a > b)
        ergebnis = a;
    return ergebnis;
}

int main()
{
    int a = 15, b = 8;
    double x = 6.3, y = 8.3;
    postenTyp pEins {2,1.45,"Apfel"};
    postenTyp pZwei {5,0.75,"Kiwi"};

    if(pEins > pZwei)
        std::cout << "pEins groesser als pZwei" << '\n';
    else
        std::cout << "pZwei groesser als pEins" << '\n';

    std::cout << maximum(a, b) << '\n';
    std::cout << maximum(x, y) << '\n';
    maximum(pEins, pZwei).ausgeben();
}
