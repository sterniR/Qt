#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

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
   srand((unsigned int)time(nullptr));

   for(int i=0; i<5; i++)
   {
      a = rand() % 20 + 20;
      b = rand() % 20 + 20;
      c = a + b;
      cout << "Aufgabe " << i+1 << ": " << a << " + " << b << " = ";
      if(eingabe() == c)
         zaehler++;
   }

   cout << "Richtig: " << zaehler << " von 5" << endl;
}

