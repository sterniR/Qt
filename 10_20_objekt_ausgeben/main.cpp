#include <iostream>
#include <string>

class postenTyp
{
private:
    int anzahl;
    double preis;
    std::string bezeichnung;
public:
    postenTyp(const int&, const double&, const std::string&);
    friend std::ostream& operator << (std::ostream&, const postenTyp&);
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

int main()
{
    postenTyp pEins{2,5.7,"Ananas"};
    std::cout << pEins << '\n';
}
