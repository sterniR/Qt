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

typedef struct rTyp
{
   int nummer;
   vector<postenTyp> pFeld;
} rechnungTyp;

int main()
{
   rechnungTyp rEins;
   rEins.nummer = 4711;
   rEins.pFeld.resize(2);

   rEins.pFeld.at(0).anzahl = 3;
   rEins.pFeld.at(0).preis = 1.45;
   rEins.pFeld.at(0).bezeichnung = "Apfel";

   rEins.pFeld.at(1) = {7, 0.85, "Birne"};
   
   rEins.pFeld.push_back( {5, 0.75, "Kiwi"} );

   cout << "Rechnung Nr.: " << rEins.nummer << endl;
   for(int i=0; i<rEins.pFeld.size(); i++)
      cout << rEins.pFeld.at(i).anzahl << " "
           << rEins.pFeld.at(i).preis << " "
           << rEins.pFeld.at(i).bezeichnung << endl;
   cout << endl;

   cout << "Rechnung Nr.: " << rEins.nummer << endl;
   for(const postenTyp& p : rEins.pFeld)
      cout << p.anzahl << " " << p.preis
         << " " << p.bezeichnung << endl;
}

