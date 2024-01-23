#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class postenTyp
{
   private:
      int anzahl;
      double preis;
      string bezeichnung;
   public:
      postenTyp(const int&, const double&, const string&);
      bool operator > (const postenTyp&);
      void ausgeben();
};

postenTyp::postenTyp(const int& a, const double& p, const string& b)
{
   anzahl = a;
   preis = p;
   bezeichnung = b;
}

bool postenTyp::operator > (const postenTyp& anderesObjekt)
{
   if(anzahl * preis > anderesObjekt.anzahl * anderesObjekt.preis)
      return true;
   else
      return false;
}

void postenTyp::ausgeben()
{
   cout << setw(2) << anzahl << " "
        << setw(5) << preis << " "
        << setw(5) << anzahl * preis << " "
        << bezeichnung << endl;
}

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
         if(pFeld.at(i) > pFeld.at(i+1))
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
   for(postenTyp& p : pFeld)
      p.ausgeben();
   cout << endl;
}

