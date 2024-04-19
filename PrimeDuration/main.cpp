#include <iostream>
#include <chrono>
#include <set>
#include <vector>
#include <deque>
int main()
{
    std::chrono::time_point<std::chrono::system_clock> beginn = std::chrono::system_clock::now();
    int x, z = 0, y;
    std::vector<long long> feld;
    std::set<long long> mfeld;
    std::deque<long long> dfeld;
    for(long long p=2; p<150000; p++)
    {
        y = p;
        for(int i=2; i<p; i++)
        {
            x = i;
            while(p % i != 0)
            {
                x++;
                i++;
                if(i == p)
                    break;
            }
            if(x == y)
            {
                z++;
                if(z == 1)
                {
                    //std::cout << p << '\n';
                    //feld.push_back(p);        // vector
                    //mfeld.insert(p);          // set
                    //dfeld.push_back(p);       // deque
                    z = 0;
                    break;
                }
            }
            break;
        }
    }
    std::chrono::system_clock::time_point ende = std::chrono::system_clock::now();
    std::chrono::duration<double> dauer = ende - beginn;
    std::cout << "Duration: " << dauer.count() << '\n';
    /*for(long long p : dfeld)
        std::cout << p << '\n';*/
    return 0;
}
