#include <iostream>
using namespace std;
int main()
{
   int xa = 42, xb{43};
   xa = 44;
   xb = {45};
   cout << xa << " " << xb << endl;

   int xc{}, xd;
   cout << xc << " " << xd << endl;

   int xe = 46.9;
   xe = xe - 0.1;
   cout << xe << endl;

   // int xf{47.9};
   // xf = {48.9};

   double da{49};
   da -= 0.5;
   cout << xe << " " << da << endl;
}

