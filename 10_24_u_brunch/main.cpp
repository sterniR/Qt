#include <iostream>
#include <cmath>

class bruch
{
private:
    int zeahler;
    int nenner;
public:
    bruch();
    bruch(const int&);
    bruch(const int& a, const int& b);
    void b1();
    friend std::ostream& operator << (std::ostream&, const bruch&);

};

bruch::bruch()
{
    int z = 1;
    int n = 1;
    zeahler = z;
    nenner = n;
}

bruch::bruch(const int& a)
{
    int z = a;
    int n = 1;
    zeahler = z;
    nenner = n;
}

bruch::bruch(const int& a, const int& b)
{
    int z = a;
    int n = b;
    zeahler = z;
    nenner = n;
}

std::ostream& operator << (std::ostream& om, const bruch& b)
{
    om << b.zeahler << "/" << b.nenner;
    return om;
}

int main()
{
    bruch b1;   std::cout << "b1: " << b1 << '\n';
    bruch b2(7);   std::cout << "b2: " << b2 << '\n';
    bruch b3(6,5);   std::cout << "b3: " << b3 << '\n';
}
