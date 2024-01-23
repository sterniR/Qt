#include <iostream>
#include <array>
#include <random>
using namespace std;

int main()
{
   default_random_engine gen;
   binomial_distribution<int> verteilung(9, 0.9);

   array<int,10> p{};
   for(int i=0; i<10000; i++)
      p.at(verteilung(gen))++;

   for(int i=0; i<10; ++i)
      cout << i << ": " << p.at(i)<< endl;
}

