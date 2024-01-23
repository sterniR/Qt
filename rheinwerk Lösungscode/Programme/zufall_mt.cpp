#include <iostream>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
   cout << "Maximum: " << mt19937::max() << endl;

   mt19937 gen;
   gen.seed(system_clock::now().time_since_epoch().count());

   for(int i=1; i<=10; i++)
      cout << gen() % 6 + 1 << " ";
   cout << endl;
}
