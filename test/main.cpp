#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

void fkt(const time_point<system_clock> &beginn, const int &nr, const int &pause)
{
    for(int i=0; i<1e10; i++)
    {
        time_point<system_clock> jetzt = system_clock::now();
        duration<double> dauer = jetzt - beginn;
        cout << "Thread " << nr << " " << i << " " << dauer.count() << endl;
        this_thread::sleep_for(milliseconds(pause));
    }
}

int main()
{
    time_point<system_clock> beginn = system_clock::now();
    cout << fixed << setprecision(6);
    thread ta(fkt, beginn, 1, 30);
    //this_thread::sleep_for(milliseconds(1000));
    thread tc(fkt, beginn, 2, 31);
    thread td(fkt, beginn, 3, 32);
    thread te(fkt, beginn, 4, 33);
    thread tf(fkt, beginn, 5, 34);
    thread tg(fkt, beginn, 6, 35);
    thread th(fkt, beginn, 7, 37);
    ta.join();
    tc.join();
    td.join();
    te.join();
    tf.join();
    tg.join();
    th.join();
}
