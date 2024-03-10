#include <iomanip>
#include <iostream>
#include <sstream>
#include <iostream>
#include <string>

int main()
{
    std::ostringstream ausgabeStrom;

    int anzahl = 3;
    double preis = 1.40;
    std::string bezeichnung = "Apfel, Bio";

    ausgabeStrom << anzahl << " " << preis << " " << bezeichnung;
    std::cout << ausgabeStrom.str() << '\n';

    ausgabeStrom.str("");
    ausgabeStrom << std::right << std::setw(4) << anzahl
                 << std::right << std::setw(8) << preis << " "
                 << std::left << std::setw(20) << bezeichnung;
    std::cout << ausgabeStrom.str() << '\n';

    ausgabeStrom.seekp(13);
    ausgabeStrom << "Birne";
    std::cout << ausgabeStrom.str() << '\n';
}
