#include <iostream>
#include <vector>
using namespace std;

void eingabeElement(vector<double>& z, int i)
{
   double eingabe;
   cout << "Eingabe " << i << ". Zahl " << ": ";
   cin >> eingabe;
   z.push_back(eingabe);
}

void ausgabeFeld(const vector<double>& z)
{
   for(int i=z.size()-1; i>=0; i--)
      cout << z.at(i) << " ";
   cout << endl;
}

int main()
{
   vector<double> zahlen;
   int weiter, nr = 1;

   do
   {
      eingabeElement(zahlen, nr);

      cout << "Noch eine Zahl (Ja=1, Nein=0)? ";
      cin >> weiter;
      nr++;
   }
   while(weiter== 1);

   cout << "Feld in umgekehrter Reihenfolge:" << endl;
   ausgabeFeld(zahlen);
}

