#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ofstream textDatei{"/home/roman/Documents/Qt/datei_schreiben.txt", ios::app};

    if(!textDatei)
    {
        std::cout << "Dateifehler" << '\n';
        return 1;
    }

    int anzahl = 3;
    double preis = 1.40;
    std::string bezeichnung = "Apfel, Bio";

    textDatei << anzahl << " " << preis << " " << bezeichnung << '\n';
    textDatei << "12 0.85 Birne" << '\n' << '\n';
}
