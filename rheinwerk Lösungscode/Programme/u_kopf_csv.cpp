#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
using namespace std::chrono;

class dsatzTyp
{
   private:
      string name;
      double zeit;
   public:
      dsatzTyp(string, double);
      dsatzTyp(string);
      void ausgeben();
      void ausgeben_csv(ofstream&);
      bool operator > (const dsatzTyp&);
};

dsatzTyp::dsatzTyp(string n, double z)
{
   name = n;
   zeit = z;
}

dsatzTyp::dsatzTyp(string dsatz)
{
   name = "";
   zeit = 0.0;

   replace(dsatz.begin(), dsatz.end(), ';', ' ');
   istringstream dsatzStrom(dsatz);

   dsatzStrom >> name;

   string zeitString;
   dsatzStrom >> zeitString;
   replace(zeitString.begin(), zeitString.end(), ',', '.');
   istringstream zeitStrom(zeitString);
   zeitStrom >> zeit;
}

void dsatzTyp::ausgeben()
{
   cout << setw(5) << zeit << " sec. " << name << endl;
}

void dsatzTyp::ausgeben_csv(ofstream& csvDatei)
{
   stringstream zeitStream;
   zeitStream << zeit;
   string zeitString = zeitStream.str();
   replace(zeitString.begin(), zeitString.end(), '.', ',');
   
   csvDatei << name << ";" << zeitString << endl;
}

bool dsatzTyp::operator > (const dsatzTyp& anderesObjekt)
{
   if(zeit > anderesObjekt.zeit)
      return true;
   else
      return false;
}

int eingabe()
{
   string ein;
   int zahl;
   istringstream strom;

   getline(cin, ein);
   if(ein == "")
      zahl = 0;
   else
   {
      strom.str(ein);
      strom >> zahl;
      strom.clear();
   }
   return zahl;
}

double differenz(time_point<system_clock> beginn)
{
   time_point<system_clock> ende = system_clock::now();
   duration<double> dauer = ende - beginn;
   return dauer.count();
}

void sortieren(vector<dsatzTyp>& dsatzFeld)
{
   bool sortiert = false;
   do
   {
      sortiert = true;
      for(int i=0; i<dsatzFeld.size()-1; i++)
      {
         if(dsatzFeld.at(i) > dsatzFeld.at(i+1))
         {
            sortiert = false;
            dsatzTyp z = dsatzFeld.at(i);
            dsatzFeld.at(i) = dsatzFeld.at(i+1);
            dsatzFeld.at(i+1) = z;
         }
      }
   }
   while(!sortiert);
}

void speichern(double zeit)
{
   string dateiName = "C:/Temp/u_kopf.csv";
   string name;
   cout << "Ihr Name: ";
   cin >> name;

   vector<dsatzTyp> dsatzFeld;
   
   ifstream csvDateiLesen{dateiName};
   if(csvDateiLesen)
   {
      while(csvDateiLesen)
      {
         string dsatz;
         getline(csvDateiLesen, dsatz);
         if(!csvDateiLesen)
            break;
         dsatzFeld.push_back({dsatz});
      }
      csvDateiLesen.close();
   }

   dsatzFeld.push_back({name, zeit});
   sortieren(dsatzFeld);
   cout << endl << "Bestzeiten:" << endl;
   for(dsatzTyp& dsatz : dsatzFeld)
      dsatz.ausgeben();

   ofstream csvDateiSchreiben{dateiName};
   if(!csvDateiSchreiben)
      cout << "Speichern nicht möglich" << endl;
   else
   {
      for(dsatzTyp& dsatz : dsatzFeld)
         dsatz.ausgeben_csv(csvDateiSchreiben);
   }
}

int main()
{
   int a, b, c, zaehler = 0;
   mt19937 z;
   z.seed(system_clock::now().time_since_epoch().count());
   time_point<system_clock> beginn = system_clock::now();

   for(int i=0; i<5; i++)
   {
      a = z() % 20 + 20;
      b = z() % 20 + 20;
      c = a + b;
      cout << "Aufgabe " << i+1 << ": " << a << " + " << b << " = ";
      if(eingabe() == c)
         zaehler++;
   }

   cout << fixed << setprecision(2);
   cout << "Richtig: " << zaehler << " von 5";
   if(zaehler == 5)
   {
      double zeit = differenz(beginn);
      cout << " in " << zeit << " sec." << endl;
      speichern(zeit);
   }
   else
      cout << endl;
}

