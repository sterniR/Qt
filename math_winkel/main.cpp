#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    double winkelGrad, winkelRadiant;
    const double pi = 4 * atan(1.0);

    std::cout << "Grad     Radiant   sin()   cos()      tan()" << std::endl;
    for(winkelGrad=80.0; winkelGrad<90.5; winkelGrad++)
    {
        winkelRadiant = winkelGrad * pi / 180.0;
        std::cout << std::fixed;
        std::cout << std::setw(1) << std::setprecision(1) << winkelGrad;
        std::cout << std::setw(12) << std::setprecision(3) << winkelRadiant;
        std::cout << std::setw(8) << std::setprecision(3) << sin(winkelRadiant);
        std::cout << std::setw(8) << std::setprecision(3) << cos(winkelRadiant);
        std::cout << std::scientific;
        std::cout << std::setw(12) << std::setprecision(2) << tan(winkelRadiant) << std::endl;
    }
}
