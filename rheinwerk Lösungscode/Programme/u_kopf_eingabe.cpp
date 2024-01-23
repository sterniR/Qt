#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
   int a, b, c, eingabe;
   srand((unsigned int)time(nullptr));

   a = rand() % 20 + 20;
   b = rand() % 20 + 20;
   c = a + b;
   cout << "Aufgabe: " << a << " + " << b << " = ";

   cin >> eingabe;
   cout << "Ihre Eingabe: " << eingabe << endl;
   cout << "Ergebnis: " << c << endl;
}
