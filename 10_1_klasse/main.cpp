#include <iostream>
#include <string>

class postenTyp
{
private:
    int anzahl;
    double preis;
    std::string bezeichnung;
public:
    void werteZuweisen(const int &a, const double &p, const std::string &b)
    {
        anzahl = a;
        preis = p;
        bezeichnung = b;
    }
    void ausgabe()
    {
        std::cout << anzahl << " " << preis << " " << bezeichnung << '\n';
    }
};

int main()
{
    postenTyp pEins;
    pEins.werteZuweisen(5, 2.5, "Himbeeren");
    pEins.ausgabe();

    postenTyp pZwei = pEins;
    pEins.ausgabe();
}
