#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
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
    return dist(generator);
}
constexpr double round_pos_twod(double v)
{
    return float (unsigned(v * 100. + 0.75) * .01f);
}
int main()
{
    generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
    int artikelAnzahl;
    double ergebnis, rechnung, zahl;
    std::string wechselGeld;
    std::vector<double> artikelFeld;
    std::istringstream eingabeStrom;

    artikelAnzahl = genInt();
    artikelFeld.resize(artikelAnzahl);

    std::generate(artikelFeld.begin(), artikelFeld.end(), genDouble);
    std::cout << "Zu zahlen: " ;
    for(int i = 0; i < artikelFeld.size(); i++)
    {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << artikelFeld.at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Gehalt: 100.00" << std::endl;
    std::cout << "Wechselgeld: ";
    std::getline(std::cin, wechselGeld);
    try {
        ergebnis = std::stod(wechselGeld);
    } catch (const std::invalid_argument&) {
        std::cout << "Falsch. Keine Zahl." << std::endl;
    }


    const double sum = std::accumulate(artikelFeld.begin(), artikelFeld.end(), 0.);
    zahl = round_pos_twod(sum);
    if(zahl == ergebnis)
    {
        std::cout << "Richtig: " << wechselGeld << " " << zahl << '\n';
    }
    else
    {
        std::cout << "Falsch: " << wechselGeld << " " << zahl << '\n';

    }



    //asm("int3");

}
