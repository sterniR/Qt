#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void aufgabe(const int& nr, int& z)
{
   int a, b, c, eingabe;
   a = rand() % 20 + 20;
   b = rand() % 20 + 20;
   c = a + b;
   cout << "Aufgabe " << nr << ": " << a << " + " << b << " = ";
   cin >> eingabe;
   if(eingabe == c)
      z++;
}

int main()
{
   int zaehler = 0;
   srand((unsigned int)time(nullptr));
   for(int i=1; i<=5; i++)
      aufgabe(i, zaehler);
   cout << "Richtig: " << zaehler << " von 5" << endl;
}
