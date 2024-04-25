#include <iostream>
#define ANZAHL 5
#define QUADRAT(x) ( (x) * (x))
#define BETRAG(x) ( (x)>0 ? (x) : -(x) )

int main()
{
    int a = 2;
    std::cout << ANZAHL << '\n';
    std::cout << QUADRAT(4) << '\n';
    std::cout << QUADRAT(2.5) << '\n';
    std::cout << QUADRAT(4 + a) << '\n';
    std::cout << BETRAG(-4) << '\n';
    std::cout << BETRAG(-2.5) << '\n';
    std::cout << 8 - BETRAG(a - 7) << '\n';
    std::cout << "Zeile " << __LINE__ << " in Datei " << __FILE__ << '\n';
    std::cout << "Kompiliert: " << __DATE__ << " " << __TIME__ << '\n';
}
