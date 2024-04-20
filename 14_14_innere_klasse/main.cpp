#include <string>
#include <iostream>

class postenTyp
{
private:
    int anzahl;
    double preis;
    std::string bezeichnung;
public:
    void werteZuweisen(int, double, std::string);
    void ausgeben();

    class fehlerKlasse
    {
    private:
        int nummer;
    public:
        std::string what();
        fehlerKlasse(const int& n) {nummer = n;};
    };
};

void postenTyp::werteZuweisen(int a, double p, std::string b) {
    if(a < 0)
        throw fehlerKlasse(1);
    anzahl = a;
    if(p < 0.0)
        throw fehlerKlasse(2);
    preis = p;
    if(b == "")
        throw fehlerKlasse(3);
    bezeichnung = b;
}

void postenTyp::ausgeben() {
    std::cout << anzahl << " " << preis << " " << bezeichnung << '\n';
}

std::string postenTyp::fehlerKlasse::what() {
    if(nummer == 1)
        return "Anzahl zu Klein";
    if(nummer == 2)
        return "Preis zu Klein";
    else
        return "Keine Bezeichnung";
}

int main()
{
    postenTyp pEins;

    try
    {
        pEins.werteZuweisen(1,1.15, "");
    }
    catch(postenTyp::fehlerKlasse& AVC)
    {
        pEins.werteZuweisen(0, 0.0, "unbekannt");
        std::cout << "Fehler: " << AVC.what() << '\n';
    }

    pEins.ausgeben();
}

