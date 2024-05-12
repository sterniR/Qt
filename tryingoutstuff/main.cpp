#include <iostream>
#include <algorithm>

int main()
{

    int* ptr = new int(0);

    std::cout << *ptr << std::endl;
    std::cout << ptr[1] << std::endl;

    int *p;
    p = (int*)malloc(sizeof(int));

    std::cout << &p[0] << std::endl;
    std::cout << &p[1] << std::endl;
    std::cout << &p[2] << std::endl;
    std::cout << &p[3] << std::endl;
    std::cout << &p[4] << std::endl;
    std::cout << *p << std::endl;
    std::cout << &p << std::endl;
    *p = 5;
    std::cout << &p << std::endl;

    delete ptr;
    return 0;
}
