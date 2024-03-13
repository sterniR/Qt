#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

class postenTyp
{
private:
    int anzahl;
    double preis;
    std::string bezeichnung;
public:
    postenTyp(std::string);
    void ausgeben();
};

postenTyp::postenTyp(std::string zeile)
{
    anzahl = 0;
    preis = 0.0;

    std::replace(zeile.begin(), zeile.end(), ';', ' ');
    std::istringstream zeilenStrom(zeile);

    zeilenStrom >> anzahl;

    std::string preisString;
    zeilenStrom >> preisString;
    std::replace(preisString.begin(),preisString.end(), ',', '.');
    std::istringstream preisStrom(preisString);
    preisStrom >> preis;

    std::getline(zeilenStrom, bezeichnung);
    while(bezeichnung.at(0) == ' ')
        bezeichnung.erase(0,1);
}

void postenTyp::ausgeben()
{
    std::cout << anzahl << " " << preis << " " << bezeichnung << '\n';
}

int main()
{
    std::ifstream textDatei{"/home/roman/Documents/Qt/datei_schreiben.csv"};
    if(!textDatei)
    {
        std::cout << "error\n";
        return 1;
    }

    std::vector<postenTyp> pFeld;
    while(textDatei)
    {
        std::string zeile;
        std::getline(textDatei, zeile);
        if(!textDatei)
        {
            break;
        }
        pFeld.push_back(postenTyp{zeile});
    }

    for(postenTyp& p : pFeld)
    {
        p.ausgeben();
    }
}
