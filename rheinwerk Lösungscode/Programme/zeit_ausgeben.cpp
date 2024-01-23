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
   time_point<system_clock> za = system_clock::now();
   time_t zb = system_clock::to_time_t(za);
   tm zc = *localtime(&zb);

   cout << "Sekunden seit 01.01.1970 00:00 Uhr UTC: "
      << zb << endl;
   cout << put_time(&zc, "%d.%m.%Y %H:%M:%S") << endl;
   cout << put_time(&zc, "Tag im Jahr: %j") << endl;

   array <string,7> tagFeld{"Sonntag", "Montag", "Dienstag",
      "Mittwoch", "Donnerstag", "Freitag", "Samstag"};
   cout << tagFeld.at(zc.tm_wday) << endl;
}
