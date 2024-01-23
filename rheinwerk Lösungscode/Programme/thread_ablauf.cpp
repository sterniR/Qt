#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;
 
void fa()
{
   cout << "Thread 1 Beginn" << endl;
   this_thread::sleep_for(milliseconds(1500));
   cout << "Thread 1 Ende" << endl;
}
 
void fb()
{
   cout << "Thread 2 Beginn" << endl;
   this_thread::sleep_for(milliseconds(600));
   cout << "Thread 2 Ende" << endl;
}
 
int main()
{
   thread ta(fa);
   this_thread::sleep_for(milliseconds(100));
   thread tb(fb);
   this_thread::sleep_for(milliseconds(100));
   cout << "Warten auf Ende der Threads" << endl;
   ta.join();
   tb.join();
}
