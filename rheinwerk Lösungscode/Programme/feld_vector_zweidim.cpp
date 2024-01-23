#include <iostream>
#include <vector>
using namespace std;
int main()
{
   vector<vector<int>> zFeld;

   int zeilenAnzahl;
   cout << "Anzahl der Zeilen: ";
   cin >> zeilenAnzahl;

   int spaltenAnzahl;
   cout << "Anzahl der Spalten: ";
   cin >> spaltenAnzahl;

   zFeld.resize(zeilenAnzahl);
   for(int i=0; i<zFeld.size(); i++)
      zFeld.at(i).resize(spaltenAnzahl);

   for(int i=0; i<zFeld.size(); i++)
      for(int k=0; k<zFeld.at(i).size(); k++)
         zFeld.at(i).at(k) = 10 + i*10 + k;

   for(const vector<int>& zeile : zFeld)
   {
      for(const int& wert : zeile)
         cout << wert << " ";
      cout << endl;
   }
}

