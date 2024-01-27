#include <iostream>
#include <sstream>

int main(int anzahl, char *para[])
{
    double zahl, summe = 0.0;
    std::istringstream eingabeStrom;

    for(int i=1; i<anzahl; i++) {
        eingabeStrom.str(para[i]);
        eingabeStrom >> zahl;
        summe += zahl;
        eingabeStrom.clear();
    }
    std::cout << "Summe: " << summe << '\n';
}
