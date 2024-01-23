#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void ausgeben(stack<int>& x)
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
   stack <int>s;

   for(int i=0; i<5; i++)
      s.push(10 * (i+1));
   cout << "Push:      ";
   ausgeben(s);

   vector v{16, 15, 14};
   stack sd{v};

   cout << "Deduktion: ";
   while(!sd.empty())
   {
      cout << sd.top() << " ";
      sd.pop();
   }
   cout << endl;
}

