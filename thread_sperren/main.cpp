#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <iomanip>

void fa(std::mutex& m, int& x)
{
    m.lock();
    x++;
    std::cout << "Thread 1 " << x << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    m.unlock();
}

void fb(const std::chrono::time_point<std::chrono::system_clock>& beginn, std::mutex& m, int& x)
{
    m.lock();
    x++;
    std::chrono::time_point<std::chrono::system_clock> jetzt = std::chrono::system_clock::now();
    std::chrono::duration<double> dauer = jetzt - beginn;
    std::cout << "Thread 2 " << x << " " << dauer.count() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    m.unlock();
}

int main()
{
    std::mutex m;
    int x = 1000;
    std::chrono::time_point<std::chrono::system_clock> beginn = std::chrono::system_clock::now();
    std::cout << std::fixed << std::setprecision(6);

    std::thread ta(fa, ref(m), std::ref(x));
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::thread tb(fb, beginn, ref(m), std::ref(x));
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    m.lock();
    x++;
    std::chrono::time_point<std::chrono::system_clock> jetzt = std::chrono::system_clock::now();
    std::chrono::duration<double> dauer = jetzt - beginn;
    std::cout << "Thread H " << x << " " << dauer.count() << std::endl;
    m.unlock();

    ta.join();
    tb.join();
}
