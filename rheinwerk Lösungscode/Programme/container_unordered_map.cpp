#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void ausgeben(unordered_map<int, string>& x)
{
   unordered_map<int,string>::iterator pos;
   for(pos = x.begin(); pos != x.end(); pos++)
      cout << (*pos).first << "/" << (*pos).second << "   ";
   cout << endl;
}

int main()
{
   unordered_map<int,string> m;

   m.insert(pair<int,string>(30,"Bremen"));
   m.insert(pair<int,string>(10,"Berlin"));
   m.insert(pair<int,string>(10,"Potsdam"));
   cout << "insert(): ";
   ausgeben(m);

   m[60] = "Frankfurt";
   m[30] = "Hannover";
   m[20] = "Hamburg";
   cout << "[]:         ";
   ausgeben(m);

   unordered_map<int,string>::iterator pos;
   if((pos = m.find(30)) != m.end())
      cout << "find():     30/" << pos->second << endl;
   if(m.contains(30))
      cout << "contains(): 30/" << pos->second << endl;

   cout << "count():    " << m.count(30) << endl;

   m.erase(30);
   cout << "erase():    ";
   ausgeben(m);

   unordered_map<int,string> mi{{35,"Italien"},{65,"Polen"},{45,"Schweden"}};
   unordered_map<int,string> mk{{85,"Belgien"},{35,"Slowenien"}};
   mi.merge(mk);
   cout << "merge():    ";
   ausgeben(mi);
   cout << "merge():    ";
   ausgeben(mk);
   
   unordered_map md{pair{25, "Spanien"}, {15, "Irland"}, {25, "Schweiz"}};
   cout << "Anzahl:     ";
   cout << md.size() << endl;
}

