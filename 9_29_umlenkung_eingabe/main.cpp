#include <iostream>
#include <string>
#include <sstream>

int main()
{

    double zahl, summe = 0.0;
    std::string eingabe;
    std::istringstream eingabeStrom;

    for(int i = 1; i<=3; i++)
    {
    //std::cout << "BItte Zahl eingeben: ";
    getline(std::cin, eingabe);
    if(eingabe == "") {
        zahl = 0.0;
    }
    else {
        eingabeStrom.str(eingabe);
        eingabeStrom >> zahl;
        eingabeStrom.clear();
    }
    summe += zahl;
    }

    std::cout << "Summe: " << summe << '\n';
}
