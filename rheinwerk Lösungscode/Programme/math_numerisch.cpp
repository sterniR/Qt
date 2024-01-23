#include <iostream>
#include <numeric>
using namespace std;
int main()
{
   cout << "GGT von 12 und 20: "  << gcd(12, 20) << endl;
   cout << "KGV von 12 und 20: "  << lcm(12, 20) << endl;
   cout << "midpoint(), int: "    << midpoint(11, 14) << endl;
   cout << "midpoint(), double: " << midpoint(11.2, 14.3) << endl;
}

