#include <iostream>
#include <string>

class bruch
{
private:
    int zeahler;
    int nenner;
public:
    bruch();
    bruch(const int&);
    bruch(const int&, const int&);
    bruch operator + (const bruch&) const;
    bruch operator * (bruch&);
    bruch operator / (bruch&);
    bruch operator - (bruch&);
    bool operator > (bruch&);
    bool operator < (bruch&);
    bool operator == (bruch&);
    friend std::ostream& operator << (std::ostream&, const bruch&);
    void eingabe();
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
    while(z % 2 == false && z != 2)
    {
        z = z / 2;
    }
    while(z % 3 == false && z != 3)
    {
        z = z / 3;
    }
    while(z % 5 == false && z != 5)
    {
        z = z / 5;
    }
    while(z % 7 == false && z != 7)
    {
        z = z / 7;
    }
    zeahler = z;
    nenner = n;
}

bruch::bruch(const int& a, const int& b)
{
    int z = a;
    int n = b;
    int x;
    int y;
    while(z % 2 == false && n % 2 == false)
    {
        z = z / 2;
        n = n / 2;
    }
    while(z % 3 == false && n % 3 == false)
    {
        z = z / 3;
        n = n / 3;
    }
    while(z % 5 == false && n % 5 == false)
    {
        z = z / 5;
        n = n / 5;
    }
    while(z % 7 == false && n % 7 == false)
    {
        z = z / 7;
        n = n / 7 ;
    }
    zeahler = z;
    nenner = n;
}

bruch bruch::operator+(const bruch& Objekt)const
{
    bruch pTemp = *this;
    bruch ObjektPlus;
    ObjektPlus.zeahler = Objekt.zeahler + pTemp.zeahler;
    ObjektPlus.nenner = Objekt.nenner + pTemp.nenner;
    while (ObjektPlus.zeahler % 2 == false) {
        ObjektPlus.zeahler = ObjektPlus.zeahler / 2;
    }
    while (ObjektPlus.nenner % 2 == false) {
        ObjektPlus.nenner = ObjektPlus.nenner / 2;
    }
    return ObjektPlus;
}

bruch bruch::operator*(bruch& Objekt)
{
    bruch pTempt = *this;
    bruch ObjektAusgabe;
    ObjektAusgabe.zeahler = Objekt.zeahler * pTempt.zeahler;
    ObjektAusgabe.nenner = Objekt.nenner * pTempt.nenner;
    while (ObjektAusgabe.zeahler % 2 == false && ObjektAusgabe.nenner % 2 == false) {
        ObjektAusgabe.zeahler = ObjektAusgabe.zeahler / 2;
        ObjektAusgabe.nenner = ObjektAusgabe.nenner / 2;
    }
    return ObjektAusgabe;
}

bruch bruch::operator/(bruch& Objekt)
{
    bruch pTempt = *this;
    bruch ObjektAusgabe;
    ObjektAusgabe.zeahler = pTempt.zeahler / Objekt.zeahler;
    ObjektAusgabe.nenner = pTempt.nenner / Objekt.nenner;
    while (ObjektAusgabe.zeahler % 2 == false && ObjektAusgabe.nenner % 2 == false) {
        ObjektAusgabe.zeahler = ObjektAusgabe.zeahler / 2;
        ObjektAusgabe.nenner = ObjektAusgabe.nenner / 2;
    }
    return ObjektAusgabe;
}

bruch bruch::operator-(bruch& Objekt)
{
    bruch pTempt = *this;
    bruch ObjektAusgabe;
    ObjektAusgabe.zeahler = pTempt.zeahler / pTempt.nenner - Objekt.zeahler / Objekt.nenner;
    ObjektAusgabe.nenner = pTempt.zeahler / pTempt.nenner - Objekt.zeahler / Objekt.nenner;
    while (ObjektAusgabe.zeahler % 2 == false && ObjektAusgabe.nenner % 2 == false) {
        ObjektAusgabe.zeahler = ObjektAusgabe.zeahler / 2;
        ObjektAusgabe.nenner = ObjektAusgabe.nenner / 2;
    }
    return ObjektAusgabe;
}

bool bruch::operator>(bruch& Objekt)
{
    bruch pTemp = *this;
    if(pTemp.zeahler / pTemp.nenner > Objekt.zeahler / Objekt.nenner)
        return true;
    else
        return false;
}

bool bruch::operator<(bruch& Objekt)
{
    bruch pTemp = *this;
    if(pTemp.zeahler / pTemp.nenner < Objekt.zeahler / Objekt.nenner)
        return true;
    else
        return false;
}

bool bruch::operator==(bruch& Objekt)
{
    bruch pTemp = *this;
    if(pTemp.zeahler == Objekt.zeahler && pTemp.nenner == Objekt.nenner)
        return true;
    else
        return false;
}

void bruch::eingabe()
{
    std::string eingabe;
    std::cout << "Eingabe Zeahler: ";
    std::getline(std::cin, eingabe);
    try
    {
        this->zeahler = std::stoi(eingabe);
    } catch (std::exception &e) {
        std::cout << "Fehler: " << e.what() << '\n';
    }
    std::cout << "Eingabe Nenner: ";
    std::getline(std::cin, eingabe);
    try
    {
        this->nenner = std::stoi(eingabe);
    } catch (std::exception &e) {
        std::cout << "Fehler: " << e.what() << '\n';
    }
    while(this->zeahler % 2 == false && this->nenner % 2 == false)
    {
        this->zeahler = this->zeahler / 2;
        this->nenner = this->nenner / 2;
    }
    while(this->zeahler % 3 == false && this->nenner % 3 == false)
    {
        this->zeahler = this->zeahler / 3;
        this->nenner = this->nenner / 3;
    }
    while(this->zeahler % 5 == false && this->nenner % 5 == false)
    {
        this->zeahler = this->zeahler / 5;
        this->nenner = this->nenner / 5;
    }
    while(this->zeahler % 7 == false && this->nenner % 7 == false)
    {
        this->zeahler = this->zeahler / 7;
        this->nenner = this->nenner / 7 ;
    }
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
    bruch b4(2,10);     std::cout << "b4: " << b4 << '\n';
    bruch b5 = b3 * b4; std::cout << "b5: " << b5 << '\n';
    bruch b6 = b3 / b4; std::cout << "b6: " << b6 << '\n';
    bruch b7 = b3 + b4; std::cout << "b7: " << b7 << '\n';
    bruch b8 = b3 - b4; std::cout << "b8: " << b8 << '\n';
    bruch b9(3, 2);     std::cout << "b9: " << b9 << '\n';
    bruch b10 = b3 + b4 * b9; std::cout << "b10: " << b10 << '\n';
    bruch b11 = (b3 + b4) * b9; std::cout << "b11: " << b11 << '\n';
    bruch b12(60, 50); std::cout << "b12: " << b12 << '\n';
    if (b3 > b4)
        std::cout << "b3 > b4" << '\n';
    if (b4 < b3)
        std::cout << "b4 < b3" << '\n';
    if(b3 == b12)
        std::cout << "b3 == b12" << '\n';
    bruch b13;
    b13.eingabe();
    std::cout << "b13: " << b13 << '\n';
}
