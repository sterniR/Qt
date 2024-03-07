#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream textDatei {"/home/roman/Documents/Qt/datei_schreiben.txt"};
    if(!textDatei)
    {
        std::cout << "File error" << '\n';
        return 1;
    }
    int anzahl;
    double preis;
    std::string bezeichnung;

    while(textDatei)
    {
        textDatei >> anzahl;
        if(!textDatei)
            break;

        textDatei >> preis;

        getline(textDatei, bezeichnung);
        while(bezeichnung.at(0) == ' ')
            bezeichnung.erase(0,1);

        std::cout << anzahl << " " << preis << " " << " |" << bezeichnung << '\n';
    }
}
