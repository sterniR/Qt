#include <iostream>
#include <string>
#include <map>
using namespace std;

void ausgeben(multimap<int, string>& x)
{
   multimap<int,string>::iterator pos;
   for(pos = x.begin(); pos != x.end(); pos++)
      cout << (*pos).first << "/" << (*pos).second << "   ";
   cout << endl;
}

int main()
{
   multimap<int,string> m;

   m.insert(pair<int,string>(30,"Bremen"));
   m.insert(pair<int,string>(10,"Berlin"));
   m.insert(pair<int,string>(10,"Potsdam"));
   m.insert(pair<int,string>(60,"Frankfurt"));
   m.insert(pair<int,string>(30,"Hannover"));
   m.insert(pair<int,string>(20,"Hamburg"));
   cout << "insert():   ";
   ausgeben(m);

   multimap<int,string>::iterator pos;
   if((pos = m.find(30)) != m.end())
      cout << "find():     30/" << pos->second << endl;
   if(m.contains(30))
      cout << "contains(): 30/" << pos->second << endl;

   cout << "count():    " << m.count(30) << endl;

   m.erase(30);
   cout << "erase():    ";
   ausgeben(m);
   
   multimap<int,string> mi{{35,"Italien"},{65,"Polen"},{45,"Schweden"}};
   multimap<int,string> mk{{85,"Belgien"},{35,"Slowenien"}};
   mi.merge(mk);
   cout << "merge():    ";
   ausgeben(mi);
   cout << "merge():    ";
   ausgeben(mk);
   
   multimap md{pair{25, "Spanien"}, {15, "Irland"}, {25, "Schweiz"}};
   cout << "Anzahl:     ";
   cout << md.size() << endl;
}

