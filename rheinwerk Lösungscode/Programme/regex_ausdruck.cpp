#include <iostream>
#include <string>
#include <regex>
using namespace std;

void ausgabe(const string& s,
   const vector<string>& feld, const regex& r)
{
   cout << s << ": ";
   for(const string& f : feld)
      if(regex_search(f, r))
         cout << f << " ";
   cout << endl;
}

int main()
{
   vector<string> feld{"cdef", "abcd", "cd"};
   ausgabe("Beginn", feld, regex("^cd"));
   ausgabe("Ende", feld, regex("cd$"));
   ausgabe("Gesamt", feld, regex("^cd$"));

   feld = {"Mayer", "Moier", "Meyer", "Maser", "Meier"};
   ausgabe("Oder", feld, regex("M[ae][iy]er"));

   feld = {"bxcd", "abyzc", "b5cd"};
   ausgabe("Beliebiges Zeichen", feld, regex("b.c"));

   feld = {"abPcd", "abtc", "bycd", "ab2cd", "ab5c"};
   ausgabe("Zeichen aus Bereich", feld, regex("b[P-Rv-z3-6]c"));

   feld = {"ab", "abab", "ababab",
      "ab5", "ab78", "ab912", "abx", "abxy"};
   ausgabe("Anzahl", feld,
      regex("^(ab){1,2}[0-9]{0,2}[x-z]{0,1}$"));

   feld = {"bcd", "abxxxxc", "bxxaxxcd"};
   ausgabe("Beliebig oft", feld, regex("bx*c"));

   feld = {"a@b.de", "a.b@c.de", "a@b", "a@de", "a@b.fr"};
   ausgabe("Sonderzeichen", feld, regex("^.*@.*[.]de$"));
}
