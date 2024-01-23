#include <iostream>
#include <memory>
using namespace std;
int main()
{
   unique_ptr<int> zi(new int);
   *zi = 42;
   cout << "Variable: " << *zi << endl;

   int anzahl;
   cout << "Anzahl der Elemente: ";
   cin >> anzahl;

   unique_ptr<int[]> zf(new int[anzahl]);
   cout << "Werte: ";
   for(int i=0; i<anzahl; i++)
   {
      zf[i] = 10 * i;
      cout << zf[i] << " ";
   }
   cout << endl;
}

