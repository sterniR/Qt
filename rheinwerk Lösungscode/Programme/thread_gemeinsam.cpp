#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;
 
void fa(int& x)
{
   for(int i=0; i<4; i++)
   {
      x++;
      cout << "Thread 1 " << x << endl;
      this_thread::sleep_for(milliseconds(800));
   }
}

void fb(int& x)
{
   for(int i=0; i<4; i++)
   {
      x++;
      cout << "Thread 2 " << x << endl;
      this_thread::sleep_for(milliseconds(300));
   }
}

int main()
{
   int x = 1000;
   thread ta(fa, ref(x));
   this_thread::sleep_for(milliseconds(100));
   thread tb(fb, ref(x));

   for(int i=0; i<4; i++)
   {
      x++;
      cout << "Thread H " << x << endl;
      this_thread::sleep_for(milliseconds(500));
   }

   ta.join();
   tb.join();
}
