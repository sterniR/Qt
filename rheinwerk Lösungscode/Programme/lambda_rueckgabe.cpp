#include <iostream>
using namespace std;

int main()
{
   int p = 5;
   cout << "Nur Ausdruck: " <<
      [](int& a){int b = a*10; return b;}(p) << endl;

   int q = 7;
   auto x = [](const int& a) ->int {int b = a*20; return b;};
   int c = x(q);
   cout << "Gespeichertes Ergebnis: " << c << endl;
   cout << "Berechnen und ausgeben: " << x(9) << endl;
   
   cout << "Maximum: " << [](const int& a, const int& b)
      {
         if(a>b)
            return a;
         else
            return b;
      }(p, q)
      << endl;
}

