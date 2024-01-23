#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

void fa(mutex& m, int& x)
{
   m.lock();
   x++;
   cout << "Thread 1 " << x << endl;
   this_thread::sleep_for(milliseconds(800));
   m.unlock();
}

void fb(const time_point<system_clock>& beginn, mutex& m, int& x)
{
   m.lock();
   x++;
   time_point<system_clock> jetzt = system_clock::now();
   duration<double> dauer = jetzt - beginn;
   cout << "Thread 2 " << x << " " << dauer.count() << endl;
   this_thread::sleep_for(milliseconds(600));
   m.unlock();
}

int main()
{
   mutex m;
   int x = 1000;
   time_point<system_clock> beginn = system_clock::now();
   cout << fixed << setprecision(6);

   thread ta(fa, ref(m), ref(x));
   this_thread::sleep_for(milliseconds(100));
   thread tb(fb, beginn, ref(m), ref(x));
   this_thread::sleep_for(milliseconds(100));

   m.lock();
   x++;
   time_point<system_clock> jetzt = system_clock::now();
   duration<double> dauer = jetzt - beginn;
   cout << "Thread H " << x << " " << dauer.count() << endl;
   m.unlock();

   ta.join();
   tb.join();
}
