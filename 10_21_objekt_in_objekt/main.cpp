#include <iostream>
#include <string>
#include <vector>

class postenTyp
{
private:
    int anzahl;
    double preis;
    std::string bezeichnung;
public:
    postenTyp(const int&, const double&, const std::string&);
    friend std::ostream& operator << (std::ostream&, const postenTyp&);
    void ausgeben();
};

postenTyp::postenTyp(const int& a, const double& p, const std::string& b)
{
    anzahl = a;
    preis = p;
    bezeichnung = b;
}

std::ostream& operator << (std::ostream& om, const postenTyp& p)
{
    om << p.anzahl << " " << p.preis << " " << p.bezeichnung << '\n';
    return om;
}

void postenTyp::ausgeben()
{
    std::cout << anzahl << " " << preis << " " << bezeichnung << '\n';
}

class rechnungTyp
{
private:
    int nummer;
    std::vector<postenTyp> pFeld;
public:
    rechnungTyp(const int&);
    void postenHinzu(const int&, const double&, const std::string);
    void ausgeben();
};

rechnungTyp::rechnungTyp(const int& n)
{
    nummer = n;
}

void rechnungTyp::postenHinzu(const int& a, const double& p, const std::string b)
{
    pFeld.push_back(postenTyp{a, p, b});
}

void rechnungTyp::ausgeben()
{
    std::cout << nummer << std::endl;
    for(postenTyp& p : pFeld)
        p.ausgeben();
}

int main()
{
    rechnungTyp rEins{4711};
    rEins.postenHinzu(4,1.15,"Mango");
    rEins.postenHinzu(7,0.85,"Birne");
    rEins.postenHinzu(2,0.65,"Orange");
    rEins.ausgeben();
}
