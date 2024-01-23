#include <iostream>
using namespace std;

int main()
{
   []{cout << "Nur Funktion" << endl;}();

   auto x = []{cout << "Mit Bezeichner" << endl;};
   x();
   x();
}

