#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

void fa()
{
    std::cout << "Thread 1 begin" << std::endl;
    std::this_thread::sleep_for(milliseconds(1500));
    std::cout << "Thread 1 Ende" << std::endl;
}

void fb()
{
    std::cout << "Thread 2 begin" << std::endl;
    std::this_thread::sleep_for(milliseconds(600));
    std::cout << "Thread 2 Ende" << std::endl;
}

int main()
{
    std::thread ta(fa);
    std::this_thread::sleep_for(milliseconds(100));
    std::thread tb(fb);
    std::this_thread::sleep_for(milliseconds(100));
    std::cout << "Warten auf Ende der Threads" << std::endl;

    ta.join();
    tb.join();
}
