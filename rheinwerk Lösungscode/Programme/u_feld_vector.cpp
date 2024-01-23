#include <iostream>
#include <vector>
using namespace std;
int main()
{
   vector<double> zahlen;
   double eingabe;
   int weiter, nr = 1;

   do
   {
      cout << "Eingabe " << nr << ". Zahl " << ": ";
      cin >> eingabe;
      zahlen.push_back(eingabe);

      cout << "Noch eine Zahl (Ja=1, Nein=0)? ";
      cin >> weiter;
      nr++;
   }
   while(weiter == 1);

   cout << "Feld in umgekehrter Reihenfolge:" << endl;
   for(int i=zahlen.size()-1; i>=0; i--)
      cout << zahlen.at(i) << " ";
   cout << endl;
}

