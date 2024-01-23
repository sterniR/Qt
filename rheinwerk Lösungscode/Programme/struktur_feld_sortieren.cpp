#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

typedef struct pTyp
{
   int anzahl;
   double preis;
   string bezeichnung;
} postenTyp;

int main()
{
   vector<postenTyp> pFeld{ {7, 1.95, "Banane"},
      {5, 0.75, "Kiwi"}, {7, 0.85, "Birne"},
      {6, 2.1, "Mango"}, {3, 1.45, "Apfel"} };

   bool sortiert;
   do
   {
      sortiert = true;
      for(int i=0; i<pFeld.size()-1; i++)
      {
         if(pFeld.at(i).preis * pFeld.at(i).anzahl >
               pFeld.at(i+1).preis * pFeld.at(i+1).anzahl)
         {
            sortiert = false;
            postenTyp p = pFeld.at(i);
            pFeld.at(i) = pFeld.at(i+1);
            pFeld.at(i+1) = p;
         }
      }
   }
   while(!sortiert);

   cout << fixed << setprecision(2);
   for(const postenTyp& p : pFeld)
      cout << setw(2) << p.anzahl << " "
           << setw(5) << p.preis << " "
           << setw(5) << p.anzahl * p.preis << " "
           << p.bezeichnung << endl;
}

