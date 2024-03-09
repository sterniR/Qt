#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class postenTyp
{
private:
    int anzahl;
    double preis;
    std::string bezeichnung;
    static const int laenge = 35;
public:
    postenTyp();
    void zeileLesenNummer(ifstream&, const int&);
    void ausgeben();
};

postenTyp::postenTyp()
{
    anzahl = 0;
    preis = 0;
    bezeichnung = "unbekannt";
}

void postenTyp::zeileLesenNummer(ifstream& td, const int& nummer)
{
    std::cout << "Position: " << td.tellg() << '\n';
    td.seekg(nummer * laenge);
    std::cout << "Position: " << td.tellg() << '\n';

    td >> anzahl >> preis;
    std::getline(td, bezeichnung);
    while(bezeichnung.at(0) == ' ')
        bezeichnung.erase(0,1);
}

void postenTyp::ausgeben()
{
    cout << anzahl << " " << preis << " |" << bezeichnung << endl;
}

int main()
{
    //std::ifstream textDatei{"/home/roman/Documents/Qt/datei_schreiben.txt"};
    std::ifstream textDatei{"C:/Temp/datei_schreiben.txt"};
    if(!textDatei)
    {
        std::cout << "Fehler" << '\n';
        return 1;
    }

    postenTyp pEins;
    pEins.zeileLesenNummer(textDatei, 2);
    pEins.ausgeben();

    pEins.zeileLesenNummer(textDatei, 1);
    pEins.ausgeben();
}
