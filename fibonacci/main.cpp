#include <iostream>

int main()
{
    int x = 21, b = 0;

    std::cout << &x << std::endl; // 0x..(0-f)
    int *ptr = &x;
    std::cout << ptr << std::endl; //0x..0

    std::cout << &b << std::endl;



    return 0;
}
