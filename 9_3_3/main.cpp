#include <iostream>
#include <thread>
#include <chrono>

void funktion1(int& x)
{
    for(int i=0; i<4; i++)
    {
        x++;
        std::cout << "Thread 1 " << x << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
    }
}

void funktion2(int& x)
{
    for(int i=0; i<4; i++)
    {
        x++;
        std::cout << "Thread 2 " << x << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

int main()
{
    int x = 1000;
    std::thread ta(funktion1, std::ref(x));
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::thread tb(funktion2, std::ref(x));

    for(int i=0; i<4; i++)
    {
        x++;
        std::cout << "Thread H " << x << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }


    ta.join();
    tb.join();
}
