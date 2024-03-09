#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

class postenTyp
{
private:
    int anzahl;
    double preis;
    std::string bezeichnung;
public:
    postenTyp(const int&, const double&, const std::string&);
    void zeileSchreiben(ofstream&);
};

postenTyp::postenTyp(const int& a, const double& p, const std::string& b)
{
    anzahl = a;
    preis = p;
    bezeichnung = b;
}

void postenTyp::zeileSchreiben(ofstream& td)
{
    td << right << std::setw(4) << anzahl
       << right << std::setw(8) << preis << " "
       << left << std::setw(20) << bezeichnung << '\n';
    std::cout << "Position: " << td.tellp() << '\n';
}

int main()
{
    //std::ofstream textDatei{"/home/roman/Documents/Qt/datei_schreiben.txt"};
    std::ofstream textDatei{"C:/Temp/datei_schreiben.txt"};
    if(!textDatei)
    {
        std::cout << "Fehler" << '\n';
        return 1;
    }

    vector<postenTyp> pFeld;
    pFeld.push_back(postenTyp{3, 1.40, "Apfel, Bio"});
    pFeld.push_back(postenTyp{12, 0.85, "Birne"});
    pFeld.push_back(postenTyp{5, 0.75, "Kiwi"});

    textDatei << fixed << std::setprecision(2);
    for(postenTyp p : pFeld)
        p.zeileSchreiben(textDatei);
}
