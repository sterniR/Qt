#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>
#include <cmath>
using namespace std;
using namespace std::chrono;

int main()
{
   int anzahl;
   vector<double> posten;
   double ergebnis, differenz, eingabe;
   mt19937 z;
   z.seed(system_clock::now().time_since_epoch().count());
   cout << fixed << setprecision(2);

   anzahl = z() % 4 + 2;
   cout << "Zu zahlen: ";
   for(int i=0; i<anzahl; i++)
   {
      posten.push_back((500 + z() % 1000) * 0.01);
      ergebnis += posten.at(i);
      cout << posten.at(i) << " ";
   }
   ergebnis = 100 - ergebnis;
   cout << endl << "Gezahlt: 100.00" << endl << "Wechselgeld: ";

   cin >> eingabe;
   if(fabs(eingabe - ergebnis) < 0.001)
      cout << "Richtig" << endl;
   else
      cout << "Falsch, richtig ist: " << ergebnis << endl;
}

