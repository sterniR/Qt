using namespace std;
#include <iostream>
#include <chrono>
int main()
{
    std::chrono::time_point<std::chrono::system_clock> beginn = std::chrono::system_clock::now();
    unsigned long long a=0,b=1,c;
    for(int i=1; i<1000000000; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    std::chrono::system_clock::time_point ende = std::chrono::system_clock::now();
    std::chrono::duration<double> dauer = ende - beginn;
    std::cout << "Duration: " << dauer.count() << '\n';

}
