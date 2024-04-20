#include <string>
#include <iostream>

class fehlerKlasse {
private:
    int nummer;
public:
    std::string what();
    fehlerKlasse(const int&);
};

fehlerKlasse::fehlerKlasse(const int& n) {
    nummer = n;
}

std::string fehlerKlasse::what() {
    if(nummer == 1)
        return "Anzahl zu Klein";
    if(nummer == 2)
        return "Preis zu Klein";
    else
        return "Keine Bezeichnung";
}

class PostenTyp {
private:
    int anzahl;
    double preis;
    std::string bezeichnung;
public:
    void werteZuweisen(const int&, const double&, const std::string&);
    void ausgeben();
};

void PostenTyp::ausgeben() {
    std::cout << anzahl << " " << preis << " " << bezeichnung << '\n';
}

void PostenTyp::werteZuweisen(const int& a, const double& p, const std::string& b) {
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

int main()
{
    PostenTyp pEins;

    try
    {
        pEins.werteZuweisen(1,1.15, "");
    }
    catch (fehlerKlasse& e)
    {
        pEins.werteZuweisen(0,0, "unbekannt");
        std::cout << "Fehler: " << e.what() << '\n';
    }
    pEins.ausgeben();
}
