#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <chrono>
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

double differenz(time_point<system_clock> beginn)
{
   time_point<system_clock> ende = system_clock::now();
   duration<double> dauer = ende - beginn;
   return dauer.count();
}

int main()
{
   int a, b, c, zaehler = 0;
   mt19937 z;
   z.seed(system_clock::now().time_since_epoch().count());
   time_point<system_clock> beginn = system_clock::now();

   for(int i=0; i<5; i++)
   {
      a = z() % 20 + 20;
      b = z() % 20 + 20;
      c = a + b;
      cout << "Aufgabe " << i+1 << ": " << a << " + " << b << " = ";
      if(eingabe() == c)
         zaehler++;
   }

   cout << "Richtig: " << zaehler << " von 5";
   if(zaehler == 5)
      cout << " in " << differenz(beginn) << " sec." << endl;
   else
      cout << endl;
}
