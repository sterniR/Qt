#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;
 
void fkt(const time_point<system_clock>& beginn,
   const int& nr, const int& pause)
{
   for(int i=0; i<5; i++)
   {
      time_point<system_clock> jetzt = system_clock::now();
      duration<double> dauer = jetzt - beginn;
      cout << "Thread " << nr << " " << i
         << " " << dauer.count() << endl;
      this_thread::sleep_for(milliseconds(pause));
   }
}
 
int main()
{
   time_point<system_clock> beginn = system_clock::now();
   cout << fixed << setprecision(6);
   thread ta(fkt, beginn, 1, 800);
   this_thread::sleep_for(milliseconds(1000));
   thread tb(fkt, beginn, 2, 300);
   ta.join();
   tb.join();
}

