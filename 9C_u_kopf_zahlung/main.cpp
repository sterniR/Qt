#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <random>
#include <chrono>
#include <iomanip>
std::mt19937 generator;
int genInt()
{
    static std::uniform_int_distribution<int> dist(2, 5);
    return dist(generator);
}
double genDouble() {
    static std::uniform_real_distribution<double> dist(5.00, 14.99);
    double zahl = std::ceil(dist(generator) * 100.00) / 100.00;
    return zahl;
}
constexpr double round_pos_twod(double v)
{
    return float (unsigned(v * 100. + 0.75) * .01f);
}
int main()
{
    std::cout << std::fixed << std::setprecision(2);
    generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
    int artikelAnzahl;
    double ergebnis = 0.00, rechnung = 0.00;
    std::string wechselGeld;
    std::vector<double> artikelFeld;
    artikelAnzahl = genInt();
    artikelFeld.resize(artikelAnzahl);
    std::generate(artikelFeld.begin(), artikelFeld.end(), genDouble);
    std::cout << "Zu zahlen: " ;
    for(int i = 0; i < artikelFeld.size(); i++)
    {
        std::cout << artikelFeld.at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Portemonnaie: 100.00" << std::endl;
    std::cout << "Wechselgeld: ";
    std::getline(std::cin, wechselGeld);
    try {
        ergebnis = std::stod(wechselGeld);
    } catch (const std::invalid_argument&) {
        std::cout << "Falsch. Keine Zahl." << std::endl;
    }
    for(int i = 0; i < artikelFeld.size(); i++)
    {
        rechnung += artikelFeld.at(i);
    }
    double final = 100.00 - rechnung;
    if(ergebnis == final)
    {
        std::cout << "Richtig" << '\n';
        std::cout << "Eingabe: " << ergebnis << '\n';
        std::cout << "Wechselgeld: " << final << '\n';
    }
    else
    {
        std::cout << "Falsch" << '\n';
        std::cout << "Eingabe: " << ergebnis << '\n';
        std::cout << "Wechselgeld: " << final << '\n';
    }
}

//Test commit 1/26/2024
