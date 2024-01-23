#include <iostream>
#include <set>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

void ausgeben(multiset<int>& x)
{
   multiset<int>::iterator pos;
   for(pos = x.begin(); pos != x.end(); pos++)
      cout << *pos << " ";
   cout << endl;
}

int main()
{
   multiset<int> s;

   mt19937 gen(system_clock::now().time_since_epoch().count());
   cout << "insert():      ";
   for(int i=0; i<8; i++)
   {
      int z = gen() % 6 + 1;
      cout << z << " ";
      s.insert(z);
   }
   cout << endl;
   cout << "set:           ";
   ausgeben(s);

   cout << "count(6):      " << s.count(6) << endl;

   if(s.find(3) != s.end())
      cout << "find():        3" << endl;
   if(s.contains(3))
      cout << "contains():    3" << endl;

   set<int>::iterator pos;
   pos = s.lower_bound(6);
   if(pos != s.end())
      cout << "lower_bound(): "  << *pos << endl;
   pos = s.upper_bound(1);
   if(pos != s.end())
      cout << "upper_bound(): "  << *pos << endl;

   s.erase(3);
   s.erase(4);
   cout << "erase():       ";
   ausgeben(s);

   s.clear();
   cout << "clear():";
   ausgeben(s);
   
   multiset sd{6, 1, 2, 6, 3};
   cout << "Liste:         ";
   ausgeben(sd);

   multiset sk{4, 6, 3};
   sd.merge(sk);
   cout << "merge():       ";
   ausgeben(sd);
   cout << "merge():       ";
   ausgeben(sk);
}

