#include <iostream>
#include <array>
using namespace std;
int main()
{
   array<double,5> zahlen;

   for(int i=0; i<zahlen.size(); i++)
   {
      cout << "Eingabe " << i+1 << ". Zahl" << ": ";
      cin >> zahlen.at(i);
   }

   cout << "Feld in umgekehrter Reihenfolge:" << endl;
   for(int i=zahlen.size()-1; i>=0; i--)
      cout << zahlen.at(i) << " ";
   cout << endl;
}

