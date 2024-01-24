#include <iostream>
#include <string>

class postenTyp
{
private:
    int anzahl;
    double preis;
    std::string bezeichnung;
public:
    void wertZuweisen(const int&, const double&, const std::string&);
    void ausgeben();
    postenTyp() { // Constructor
        std::cout << "Special Method!" << std::endl;
    }
};

void postenTyp::wertZuweisen(const int& a, const double& p, const std::string& b)
{
    anzahl = 5;
    preis = p;
    bezeichnung = b;
}

void postenTyp::ausgeben()
{
    std::cout << anzahl << " " << preis << " " << bezeichnung << std::endl;
}

int main()
{
    postenTyp pEins;
    pEins.wertZuweisen(2, 1.45, "Apfel");
    pEins.ausgeben();
    postenTyp pZwei = pEins;
    pZwei.ausgeben();
    postenTyp pDrei;
    pDrei;  // Call Constructor
}
