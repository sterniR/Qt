#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct pTyp
{
   int anzahl;
   double preis;
   string bezeichnung;
} postenTyp;

int main()
{
   vector<postenTyp> pFeld;

   pFeld.resize(2);
   pFeld.at(0) = {3, 1.45, "Apfel"};
   pFeld.at(1) = {7, 0.85, "Birne"};

   pFeld.push_back( {5, 0.75, "Kiwi"} );

   for(int i=0; i<pFeld.size(); i++)
      cout << pFeld.at(i).anzahl << " "
           << pFeld.at(i).preis << " "
           << pFeld.at(i).bezeichnung << endl;
   cout << endl;

   for(const postenTyp& p : pFeld)
      cout << p.anzahl << " " << p.preis
         << " " << p.bezeichnung << endl;
}

