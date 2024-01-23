#include <iostream>
#include <string>
#include <sstream>
#include <random>

#include <chrono>
#include <ctime>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int eingabe()
{
    string ein;
    int zahl;
    istringstream strom;

    getline(cin, ein);
    if(ein == "")
        zahl = 0;
    else
    {
        strom.str(ein);
        strom >> zahl;
        strom.clear();
    }
    return zahl;
}

int main()
{
    int a, b, c, zaehler = 0;

    mt19937 generator;
    generator.seed(system_clock::now().time_since_epoch().count());


    time_point<system_clock> zeitNullpunkt = system_clock::now(); //Datum/Uhrzeit Berechnung
    time_t berechneteZeitseitNullpunktInSekunden = system_clock::to_time_t(zeitNullpunkt);
    tm berechneteZeitmitFormat = *localtime(&berechneteZeitseitNullpunktInSekunden);

    cout << put_time(&berechneteZeitmitFormat, "%d.%m.%Y") << endl;
    cout << put_time(&berechneteZeitmitFormat, "%H:%M:%S Uhr") << endl;
    cout << endl;

    time_point<system_clock> beginn = system_clock::now();  // Start der Messung (in Sekunden)
    for(int i=0; i<5; i++)
    {
        a = generator() % 20 + 20;
        b = generator() % 20 + 20;
        c = a + b;
        cout << "Aufgabe " << i+1 << ": " << a << " + " << b << " = ";
        if(eingabe() == c)
            zaehler++;
    }

    time_point<system_clock> ende = system_clock::now(); //Ende der Messung
    duration<double> dauer = ende - beginn;

    cout << "Richtig: " << zaehler << " von 5 in " << dauer.count() << " Sekunden." << endl;



}

