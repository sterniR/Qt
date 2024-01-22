#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <array>
#include <string>
using namespace std;
using namespace std::chrono;

int main()
{
    time_point<system_clock> zeitNow = system_clock::now();
    time_t zeitB = system_clock::to_time_t(zeitNow);
    tm zeitC = *localtime(&zeitB);

    cout << "Sekunden seit 01.01.1970 00:00 Uhr UTC: " << zeitB << endl;
    cout << put_time(&zeitC, "%d.%m.%Y %H:%M:%S") << endl;
    cout << put_time(&zeitC, "Tag im Jahr: %j") << endl;

    array <string, 7> tagFeld{"Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag"};

    cout << tagFeld.at(zeitC.tm_wday) << endl;
}
