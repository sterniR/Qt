#include <iostream>
#include <array>

void ausgeben(std::array<int,5>& x)
{
    std::array<int,5>::iterator position;
    for(position = x.begin(); position != x.end(); position++)
        std::cout << *position << " ";
    std::cout << '\n';
}

int main()
{
    std::array <int,5> a;
    for(int i=0; i<a.size(); i++)
    {
        a.at(i) = 10 * (i+1);
    }
    std::cout << "at():          ";
    ausgeben(a);

    int wert = 11;
    for(int& z : a)
    {
        z = wert;
        wert += 10;
    }
    std::cout << "for:           ";
    ausgeben(a);


    std::array <int,5> b;

    b = a;
    std::cout << "Zuweisung:     ";
    ausgeben(b);

    b.fill(42);
    std::cout << "fill():        ";
    ausgeben(b);

    std::array<int,5> c{15,12,19,16,11};
    b.swap(c);
    std::cout << "swap(c):       ";
    ausgeben(b);

    std::array<int,5> d;
    d = {15, 12,19,16,11};
    if(d == b)
        std::cout << "array-Felder sind gleich\n";
    if(d != c)
        std::cout << "array-Felder sind ungleich\n";

    std::array e{12,22,32,42,52};
    std::cout << "Deduktion: ";
    ausgeben(e);


}
