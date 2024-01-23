#include <iostream>
#include <array>
using namespace std;
int main()
{
   array<array<int,7>,3> zFeld;

   for(int i=0; i<zFeld.size(); i++)
      for(int k=0; k<zFeld.at(i).size(); k++)
         zFeld.at(i).at(k) = 10 + i*10 + k;

   for(const array<int,7>& zeile : zFeld)
   {
      for(const int& wert : zeile)
         cout << wert << " ";
      cout << endl;
   }
}

