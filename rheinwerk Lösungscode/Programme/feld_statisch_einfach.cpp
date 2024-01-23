#include <iostream>
using namespace std;
int main()
{
   double preise[3];

   preise[0] = 1.45;
   preise[1] = 0.85;
   preise[2] = 0.75;

   for(int i=0; i<3; i++)
      cout << "Element " << i << ": " << preise[i] << endl;

   double summe = 0.0;
   for(const double& p : preise)
      summe += p;
   cout << "Summe: " << summe << endl;
}

