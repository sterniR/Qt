#include <iostream>
using namespace std;

int main()
{
   int a = 5, b = 7;
   [a, &b]{b += 100;
      cout << "Mit Capture: " << a << " " << b << endl;}();
   cout << "Nachher: " << a << " " << b << endl;

   int c = 9;
   auto x = [c]{cout << "Wert bei Definition: " << c << endl;};
   c = 109;
   x();
   cout << "Nachher: " << c << endl;
}

