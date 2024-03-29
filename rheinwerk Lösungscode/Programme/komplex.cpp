#include <iostream>
#include <complex>
using namespace std;
int main()
{
   complex<double> c1, c2{5.1}, c3{0, 1.7};
   cout << c1 << " " << c2 << " " << c3 << endl;

   complex<double> c4{3.5, 3.5}, c5{c4};
   cout << c4 << " " << c5 << endl;

   c1 = 2.5;
   c2 = c3;
   cout << c1 << " " << c2 << endl;

   complex<double> c6{2.9 + 6.2i};
   complex<double> c7, c8;
   c7 = 4.8 - 7.9i;
   c8 = 2.6i;
   cout << c6 << " " << c7 << " " << c8 << endl;
}
