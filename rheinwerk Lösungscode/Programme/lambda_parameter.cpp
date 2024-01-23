#include <iostream>
using namespace std;

int main()
{
   [](int a){cout << "Parameter: " << a << endl;}(5);

   int p = 13, q = 15;
   [](int a, int& b, const int& c){a++; b++;
      cout << "Art: " << a << " "
	     << b << " " << c << endl;}(p, q, 17);
   cout << "Nachher: " << p << " " << q << endl;
   
   int f = 5, g = 7;
   auto x = [](int a, int b){int c = a+b;
      cout << "Summe: " << c << endl;};
   x(f, g);
   x(f, 24);
}
