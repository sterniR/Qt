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
    bruch operator + (bruch&);
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

bruch bruch::operator + (bruch& ObjektPlus)
{
    bruch pTemp = *this;
    ObjektPlus = (pTemp.zeahler / pTemp.nenner) + (ObjektPlus.zeahler / ObjektPlus.nenner);
    return ObjektPlus;
}

std::ostream& operator << (std::ostream& om, const bruch& b)
{
    om << b.zeahler << "/" << b.nenner;
    return om;
}

int main()
{
    bruch b1;           std::cout << "b1: " << b1 << '\n';
    bruch b2(7);        std::cout << "b2: " << b2 << '\n';
    bruch b3(6,5);      std::cout << "b3: " << b3 << '\n';
    bruch b4(1,5);      std::cout << "b4: " << b4 << '\n';
    bruch b7 = b3 + b4; std::cout << "b7: " << b7 << '\n';
}
