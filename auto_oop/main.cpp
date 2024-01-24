#include <iostream>
#include <string>


//Fahrzeugfabrik,
//PKW, LKW, Busse, Motorraeder
//Lack-Farbe, Anzahl der Sitze, Ledersitze, Infotainment

class autofabrik {
private:
    std::string fahrzeugArt;
    std::string marke;
    std::string modell;
    int baujahr;
public:
    autofabrik(); // Constructor
    void autofabrik1(const std::string& , const std::string& , const std::string , const int); // Method
    void ausgabe(); // Method
};

autofabrik::autofabrik() { // Constructor
    fahrzeugArt = "LKW";
    marke = "Audi";
    modell = "X12";
    baujahr = 2018;
}

void autofabrik::autofabrik1(const std::string& fahrzeugartAusgabe, const std::string& markeAusgabe, const std::string modellAusgabe, const int baujahrAusgabe) { // Method
    fahrzeugArt = fahrzeugartAusgabe;
    marke = markeAusgabe;
    modell = modellAusgabe;
    baujahr = baujahrAusgabe;
}

void autofabrik::ausgabe() { // Method
    std::cout << "Fahrzeug: " << fahrzeugArt << "." << '\n' << "Marke: " << marke << ". Modell: " << modell << ". Baujahr: " << baujahr << '\n';
}
int main()
{
    autofabrik auto0; // Constructor
    auto0.ausgabe();

    std::cout << '\n';

    autofabrik auto1; // Method
    auto1.autofabrik1("PKW","BMW","X95",2015);
    auto1.ausgabe();
}
