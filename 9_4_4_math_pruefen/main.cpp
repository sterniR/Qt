#include <iostream>
#include <cmath>

int main()
{
    double x = pow(-4.5, 3.5);
    std::cout << "-4.5 hoch 3.5 = " << x << std::endl;

    if(std::isnan(x))
    {
        std::cout << "Das ist keine Zahl." << std::endl;
    }

    x = 1.7e308;
    if(std::isfinite(x))
    {
        std::cout << "1.7e308 is finit." << std::endl;
    }

    x = x * 10;
    if(std::isinf(x))
    {
        std::cout << "1.7e308 is infinite." << std::endl;
    }
}
