#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    std::cout << "|-6.75| = " << fabs(-6.75) << std:: endl;
    std::cout << "|-4| = " << abs(-4) << std:: endl;

    std::cout << std::fixed << std::setprecision(15);
    double a = 1.0/7.0;
    std::cout << a << std::endl;
    double b = 0.142857;
    std::cout << b << std::endl;

    std::cout << a-b << std::endl;
    if(fabs (a-b) < 1e-6)
        std::cout << "1e-6: Werte sind gleich." << std::endl;
    if(fabs (a-b) < 1e-7)
        std::cout << "1e-6: Werte sind gleich." << std::endl;
}
