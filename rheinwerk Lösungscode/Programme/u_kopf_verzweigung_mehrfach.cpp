#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
   int op, a, b, c, eingabe;
   srand((unsigned int)time(nullptr));

   op = rand() % 4;
   if(op == 0)
   {
      a = rand() % 20 + 20;
      b = rand() % 20 + 20;
      c = a + b;
      cout << "Aufgabe: " << a << " + " << b << " = ";
   }
   else if(op == 1)
   {
      a = rand() % 20 + 20;
      b = rand() % 20 + 20;
      c = a - b;
      cout << "Aufgabe: " << a << " - " << b << " = ";
   }
   else if(op == 2)
   {
      a = rand() % 10 + 5;
      b = rand() % 10 + 5;
      c = a * b;
      cout << "Aufgabe: " << a << " * " << b << " = ";
   }
   else
   {
      b = rand() % 10 + 5;
      c = rand() % 10 + 5;
      a = c * b;
      cout << "Aufgabe: " << a << " / " << b << " = ";
   }
   
   cin >> eingabe;
   if(eingabe == c)
      cout << "Richtig: ";
   else
      cout << "Falsch:  ";

   if(op == 0)
      cout << a << " + " << b << " = " << c << endl;
   else if(op == 1)
      cout << a << " - " << b << " = " << c << endl;
   else if(op == 2)
      cout << a << " * " << b << " = " << c << endl;
   else
      cout << a << " / " << b << " = " << c << endl;
}
