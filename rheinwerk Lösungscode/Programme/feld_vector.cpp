#include <iostream>
#include <vector>
using namespace std;
int main()
{
   vector<double> preise;

   int postenAnzahl;
   cout << "Anzahl der Rechnungsposten: ";
   cin >> postenAnzahl;
   preise.resize(postenAnzahl);

   for(int i=0; i<preise.size(); i++)
   {
      cout << "Preis von Rechnungsposten " << i+1 << ": ";
      cin >> preise.at(i);
   }
   
   double p;
   cout << "Noch ein Preis: ";
   cin >> p;
   preise.push_back(p);

   double summe = 0.0;
   for(const double& p : preise)
      summe += p;
   cout << "Summe: " << summe << endl;
}

