#include <iostream>
#include <chrono>
int main()
{
    std::chrono::time_point<std::chrono::system_clock> beginn = std::chrono::system_clock::now();
    int x, z = 0, y;
    for(int p=2; p<500000; p++)
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

}
