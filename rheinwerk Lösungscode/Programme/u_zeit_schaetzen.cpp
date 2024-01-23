#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;

int main()
{
   string eingabe;
   istringstream eingabeStrom;
   int zeit;
   double differenz, abweichung;

   do
   {
      cout << "Bitte Zeit in Sekunden eingeben, zwischen 5 und 10: ";
      getline(cin, eingabe);
      if(eingabe == "")
         zeit = 0;
      else
      {
         eingabeStrom.str(eingabe);
         eingabeStrom >> zeit;
         eingabeStrom.clear();
      }
   }
   while(zeit < 5 || zeit > 10);

   cout << endl << "Wie lang sind " << zeit << " Sekunden?" << endl;
   cout << "Starten Sie mit der Taste <Return> ";
   getline(cin, eingabe);
   time_point<system_clock> beginn = system_clock::now();

   cout << endl << zeit << " Sekunden vorbei?" << endl;
   cout << "Dann beenden Sie mit der Taste <Return> ";
   getline(cin, eingabe);
   time_point<system_clock> ende = system_clock::now();

   duration<double> dauer = ende - beginn;
   double zeit_geschaetzt = dauer.count();
   cout << endl << "Das waren " << zeit_geschaetzt << " Sekunden" << endl;
   
   differenz = fabs(zeit_geschaetzt - zeit);
   abweichung = differenz / zeit * 100;
   cout << "Eine Abweichung von " << abweichung << " %" << endl;
}
