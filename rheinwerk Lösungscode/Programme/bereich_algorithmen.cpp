#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

void ausgeben(vector<int>& x)
{
   vector<int>::iterator position;
   for(position = x.begin(); position != x.end(); position++)
      cout << *position << " ";
   cout << endl;
}

void ausgebenZahl(const int& z)
{
   cout << z << " ";
}

int main()
{
   vector<int> v{12, 27, 5, 27, 16, 9, 14};

   cout << "for_each():  ";
   for_each(v.begin(), v.end(), ausgebenZahl);
   cout << endl;

   cout << "Mit Lambda:  ";
   for_each(v.begin(), v.end(), [](int z){cout << z << " ";});
   cout << endl;

   if(find(v.begin(), v.end(), 27) != v.end())
      cout << "find():      Ja" << endl;

   cout << "count():     "
      << count(v.begin(), v.end(), 27) << endl;

   cout << "count_if():  "
      << count_if(v.begin(), v.end(),
	     [](int z){return z%2==0;}) << endl;

   replace(v.begin(), v.end(), 27, 47);
   cout << "replace():   ";
   ausgeben(v);
   
   rotate(v.begin(), v.begin() + 2, v.end());
   cout << "rotate():    ";
   ausgeben(v);
   
   mt19937 gen;
   gen.seed(system_clock::now().time_since_epoch().count());
   shuffle(v.begin(), v.end(), gen);
   cout << "shuffle():   ";
   ausgeben(v);
   
   sort(v.begin(), v.end());
   cout << "sort():      ";
   ausgeben(v);

   sort(v.begin(), v.end(), [](int a, int b){return a>b;});
   cout << "sort():      ";
   ausgeben(v);

   vector<int> vZwei{1005, 1020, 1012};
   swap(v, vZwei);
   cout << "swap:        ";
   ausgeben(v);
}

