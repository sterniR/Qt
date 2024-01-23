#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void ausgeben(queue<int>& x)
{
   while(!x.empty())
   {
      cout << x.front() << " ... " << x.back() << endl;
      x.pop();
   }
}

int main()
{
   queue<int> q;
   q.push(50);
   q.push(80);
   q.push(10);
   q.push(60);
   q.push(20);

   cout << "Push:" << endl;
   ausgeben(q);

   vector v{26, 22, 28, 20};
   queue qd{v};

   cout << endl << "Deduktion:" << endl;
   cout << qd.front() << " ... " << qd.back() << endl;
   // qd.pop();
}
