#include <iostream>
#define AUSGABE 2
#ifndef AUSGABE
    #define AUSGABE 3
#endif

int main()
{
    int summe = 0;
    for(int i=0; i<=5; i++)
    {
        summe += i;
        #if AUSGABE == 1
            std::cout << summe << '\n';
        #elif AUSGABE == 2
            std::cout << i << " " << summe << '\n';
        #elif AUSGABE == 3
            std::cout << "Zahl: " << i << ", Summe: " << summe << '\n';
        #else
            ;
        #endif
    }
}
