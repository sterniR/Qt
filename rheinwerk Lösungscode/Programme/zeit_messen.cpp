#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
   time_point<system_clock> beginn = system_clock::now();
   int a = 1;
   for(int i=1; i<3e8; i++)
      a *= -1;
   time_point<system_clock> ende = system_clock::now();
   duration<double> dauer = ende - beginn;
   cout << "Dauer: " << dauer.count() << " sec." << endl;
}
