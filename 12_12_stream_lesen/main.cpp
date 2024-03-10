#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::istringstream eingabeStrom;

    int anzahl;
    double preis;
    std::string waehrung, bezeichnung;

    eingabeStrom.str("12 0.85    Euro    Birne, Demeter   ");
    eingabeStrom >> anzahl >> preis;
    eingabeStrom >> waehrung;

    std::getline(eingabeStrom, bezeichnung);
    while(bezeichnung.at(0) == ' ')
        bezeichnung.erase(0,1);
    while(bezeichnung.at(bezeichnung.length()-1) == ' ')
        bezeichnung.pop_back();

    eingabeStrom.clear();

    std::cout << anzahl << "|" << preis << "|"
              << waehrung << "|" << bezeichnung << "|" << std::endl;

}
