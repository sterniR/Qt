#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;
using namespace std::chrono;

void ausgabe(const string& s, const time_point<system_clock>& x)
{
    time_t xa = system_clock::to_time_t(x);
    tm xb = *localtime(&xa);
    cout << s << put_time(&xb, "%d.%m.%Y %H:%M:%S") << endl;
}

int main()
{
    istringstream za{"26.07.2020 21:15:50"};
    tm zb{};
    za >> get_time(&zb, "%d.%m.%Y %H:%M:%S");
    time_t zc = mktime(&zb);
    time_point<system_clock> zd = system_clock::from_time_t(zc);

    ausgabe("Start:     ", zd);

    zd += hours(45);
    ausgabe("+45 St.: ", zd);
    zd -= minutes(85);
    ausgabe("-85 Min.: ", zd);
    zd += seconds(75);
    ausgabe("+75 Sek.: ", zd);

    // Seit C++20: days(), months(), years().
    // zd -= days(12);
    // ausgabe("-12 Tage: ", zd);
}
