#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main()
{
   vector<string> land;
   string eingabe;
   int anzahl;
   istringstream eingabeStrom;

   cout << "Anzahl: ";
   getline(cin, eingabe);
   if(eingabe == "")
   {
      cout << "Keine Eingabe" << endl;
      anzahl = 0;
   }
   else
   {
      eingabeStrom.str(eingabe);
      eingabeStrom >> anzahl;
      eingabeStrom.clear();
   }

   land.resize(anzahl);

   for(int i=0; i<land.size(); i++)
   {
      cout << "Name des Landes " << i+1 << ": ";
      getline(cin, land.at(i));
   }
   
   string L;
   cout << "Noch ein Land: ";
   getline(cin, L);
   land.push_back(L);

   for(const string& L : land)
   {
      for(const char& c : L)
         cout << c << " ";
      cout << endl;
   }
}

