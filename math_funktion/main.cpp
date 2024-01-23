#include <iostream>
#include <cmath>

int main()
{
    std::cout << "Quadratwurzel(64) = " << sqrt(64) << std::endl;
    std::cout << "Kubikwurzel(64) = " << cbrt(64) << std::endl;

    std::cout << "4 hoch 3 = " << pow(4, 3) << std::endl;
    std::cout << "-4.1 hoch -3 = " << pow(-4.1, -3) << std::endl;
    std::cout << "4.1 hoch -3 = " << pow(4.1, -3) << std::endl;

    std::cout << "10er-Logarithmus von 1000 = " << log10(1000) << std::endl;
    std::cout << "Nat. Logarithmus von 100 = " << log(100) << std::endl;
    std::cout << "e hoch 4.6 = " << exp(4.6) << std::endl << std::endl;

    std::cout << "fmod(3.75, 1.5) = " << fmod(3.75, 1.5) << std::endl;
    //9.4.3
}
