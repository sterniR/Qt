#include <iostream>
#include <array>
#include <vector>
using namespace std;
int main()
{
   array<double,3> pa{1.45, 0.85, 0.75};
   vector<double> pv{1.45, 0.85, 0.75};

   cout << "vector, Anzahl: " << pv.size() << endl;

   pa = {1.45, 0.85};
   pv = {1.45, 0.85};

   cout << "array, Element 2: " << pa.at(2) << endl;
   cout << "vector, Anzahl: " << pv.size() << endl;

   pa = {};
   pv = {};

   cout << "array, Element 0: " << pa.at(0) << endl;
   cout << "vector, Anzahl: " << pv.size() << endl;
}

