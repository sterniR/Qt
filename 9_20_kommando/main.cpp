#include <iostream>

int main(int anzahl, char *para[])
{
    std::cout << "ANzahl: " << anzahl << '\n';

    for(int i = 0; i<anzahl; i++) {
        std::cout << i << ": " << para[i] << '\n';
    }
}
