#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
   int a, b, c, eingabe, zaehler = 0;
   srand((unsigned int)time(nullptr));

   for(int i=0; i<5; i++)
   {
      a = rand() % 20 + 20;
      b = rand() % 20 + 20;
      c = a + b;
      cout << "Aufgabe " << i+1 << ": " << a << " + " << b << " = ";
      cin >> eingabe;
      if(eingabe == c)
         zaehler++;
   }

   cout << "Richtig: " << zaehler << " von 5" << endl;
}
