#include <iostream>
int main()
{
    #ifdef __unix__
        std::cout << "Unix / Linux" << '\n';
    #elif __APPLE__
        std::cout << "Apple" << '\n';
    #elif __WIN32__
        std::cout << "Windows" << '\n';
    #endif
}
