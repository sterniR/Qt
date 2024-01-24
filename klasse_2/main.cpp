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
