#include <iostream>
#include <array>
using namespace std;
int main()
{
   array<double,3> preise;

   preise.at(0) = 1.45;
   preise.at(1) = 0.85;
   preise.at(2) = 0.75;

   for(int i=0; i<preise.size(); i++)
      cout << "Element " << i << ": "
         << preise.at(i) << endl;

   double summe = 0.0;
   for(const double& p : preise)
      summe += p;
   cout << "Summe: " << summe << endl;
}

