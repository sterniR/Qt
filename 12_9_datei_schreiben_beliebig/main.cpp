#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class postenTyp
{
private:
    int anzahl;
    double preis;
    string bezeichnung;
    static const int laenge = 35;
public:
    postenTyp(const int&, const double&, const std::string&);
    void zeilenSchreibenNummer(ofstream&, int);
};

postenTyp::postenTyp(const int& a, const double& p, const std::string& b)
{
    anzahl = a;
    preis = p;
    bezeichnung = b;

}

void postenTyp::zeilenSchreibenNummer(ofstream& td, int nummer)
{
    std::cout << "Position: " << td.tellp() << '\n';
    td.seekp(laenge * nummer);
    std::cout << "Position: " << td.tellp() << '\n';

    td << right << setw(4) << anzahl
       << right << setw(8) << preis << " "
       << left << setw(20) << bezeichnung << endl;
}

int main()
{
    std::ofstream textDatei{"C:/Temp/datei_schreiben_beliebig.txt", ios::in | ios::out};
    if(!textDatei)
    {
        std::cout << "error file" << '\n';
    }

    textDatei << fixed << setprecision(2);

    postenTyp pEins{6, 2.1, "Mango"};
    pEins.zeilenSchreibenNummer(textDatei,3);
}
