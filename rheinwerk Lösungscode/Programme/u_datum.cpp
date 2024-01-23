#include <iostream>
using namespace std;
int main()
{
   int tag, monat, jahr;
   bool richtig = true;

   cout << "Tag des Datums eingeben: ";
   cin >> tag;

   cout << "Monat des Datums eingeben: ";
   cin >> monat;

   cout << "Jahr des Datums eingeben: ";
   cin >> jahr;

   if(tag < 1 || tag > 31)
      richtig = false;
   else if(monat < 1 || monat > 12)
      richtig = false;
   else if(monat == 4 || monat == 6 || monat == 9 || monat == 11)
   {
      cout << "Letzter Tag: 30" << endl;
      if(tag > 30)
         richtig = false;
   }
   else if(monat == 2)
   {
      if((jahr%4 == 0 && jahr%100 != 0) || jahr%400 == 0)
      {
         cout << "Letzter Tag: 29" << endl;
         if(tag > 29)
            richtig = false;
      }
      else
      {
         cout << "Letzter Tag: 28" << endl;
         if(tag > 28)
            richtig = false;
      }
   }
   else
   {
      cout << "Letzter Tag: 31" << endl;
   }
   
   if(richtig)
      cout << "Richtiges Datum" << endl;
   else
      cout << "Falsches Datum" << endl;
}

