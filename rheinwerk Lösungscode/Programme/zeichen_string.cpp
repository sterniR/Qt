#include <iostream>
#include <string>
using namespace std;

int main()
{
   string satz{"Das wird"};
   cout << "Initialisieren: " << satz << endl;

   satz = "Das ist";
   cout << "Zuweisen: " << satz << endl;

   satz += " ein Satz";
   cout << "Erweitern: " << satz << endl;

   for(int i=0; i<satz.length(); i++)
      cout << satz.at(i) << " ";
   cout << endl;

   for(const char& z : satz)
      cout << z << " ";
   cout << endl;

   cout << "Einfach: " << satz.c_str() << endl;

   string linie = string(10, '+');
   cout << linie << endl;

   string mehrzeilig = "Das ist"
      " ein Satz"
      " aus mehreren " "Teilen";
   cout << mehrzeilig << endl;
}

