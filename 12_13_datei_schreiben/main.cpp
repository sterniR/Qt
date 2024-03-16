#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

class postenTyp
{
private:
    int anzahl;
    double preis;
    std::string bezeichnung;
public:
    postenTyp(const int&, const double&, const std::string&);
    void ausgeben_csv(std::ofstream&);
};

postenTyp::postenTyp(const int& a, const double& p, const std::string& b)
{
    anzahl = a;
    preis = p;
    bezeichnung = b;
}

void postenTyp::ausgeben_csv(std::ofstream& td)
{
    std::stringstream preisStream;
    preisStream << preis;
    std::string preisString = preisStream.str();
    std::replace(preisString.begin(), preisString.end(), '.', ',');

    td << anzahl << ";" << preisString << ";" << bezeichnung << '\n';
}

int main()
{
    std::ofstream textDatei{"/home/roman/Documents/Qt/datei_schreiben.csv"};
    if(!textDatei)
    {
        std::cout << "error file.\n";
        return 1;
    }

    std::vector<postenTyp> pFeld;
    pFeld.push_back(postenTyp{3, 1.40, "Apfel, Bio"});
    pFeld.push_back(postenTyp{12, 0.85, "Birne"});
    pFeld.push_back(postenTyp{5, 0.75, "Kiwi"});

    for(postenTyp& p : pFeld)
    {
        p.ausgeben_csv(textDatei);
    }
}
