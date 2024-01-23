#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
   int a, b, c, eingabe;
   double faktor = 1.0;
   int modus;
   srand((unsigned int)time(nullptr));

   do
   {
      cout << "Training(=1) oder Wettkampf(=2): ";
      cin >> modus;
   }
   while(modus!=1 && modus!=2);

   cout << "Abbruch mit -1" << endl;

   do
   {
      a = faktor * (rand() % 20 + 20);
      b = faktor * (rand() % 20 + 20);
      c = a + b;
      cout << "Aufgabe: " << a << " + " << b << " = ";
      cin >> eingabe;

      if(eingabe == -1)
         break;
      else if(eingabe == c)
         faktor = faktor * 1.5;
      else
      {
         if(modus==1)
            faktor = faktor / 1.5;
         else
            break;
      }
   }
   while(true);
}
