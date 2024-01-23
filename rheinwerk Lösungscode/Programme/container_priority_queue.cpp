#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void ausgeben(priority_queue<int>& x)
{
   while(!x.empty())
   {
      cout << x.top() << " ";
      x.pop();
   }
   cout << endl;
}

int main()
{
   priority_queue<int> p;
   p.push(50);
   p.push(80);
   p.push(10);
   p.push(60);
   p.push(20);

   cout << "Push:" << endl;
   ausgeben(p);

   vector v{26, 22, 28, 20};
   queue pd{v};

   // cout << "Deduktion:" << endl;
   // cout << pd.top() << endl;
   // pd.pop();
}
