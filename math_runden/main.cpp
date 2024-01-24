#include <iostream>
#include <iomanip>>
#include <cmath>

int main()
{
    double a = 6.75, b = -6.75;
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Werte:    " << a << " " << b << std::endl;
    std::cout << "ceil(): " << ceil(a) << " " << ceil(b) << std::endl;
    std::cout << "floor(): " << floor(a) << " " << floor(b) << std::endl;
    std::cout << "round(): " << round(a) << " " << round(b) << std::endl;
    std::cout << "trunc(): " << trunc(a) << " " << trunc(b) << std::endl;
    std::cout << std::endl;

    std::cout << "Cast mit (int): " << std::endl;
    std::cout << (int) a << " " << (int) b << std::endl << std::endl;

    std::cout << "Cast mit (double): " << std::endl;
    std::cout << (double) 15 / 4 << std::endl;
    std::cout << (double) (15 / 4) << std::endl;
}
