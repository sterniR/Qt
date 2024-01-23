#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
   string sa = "Hans Mayer, Berlin";
   regex ra("Mayer");
   if(regex_search(sa, ra))
      cout << "Teil: Mayer" << endl;

   if(regex_match(sa, ra))
      cout << "Gesamt: Mayer" << endl;

   string sb = "abrakadabra";
   regex rb("abr");
   sb = regex_replace(sb, rb, "x");
   cout << "Ersetzen: " << sb << endl;
}
