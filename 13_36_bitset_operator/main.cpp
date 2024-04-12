#include <bitset>
#include <iostream>

using namespace std;

int main()
{
    bitset<8> b(12);
    cout << "b:        " << b << endl;

    std::bitset<8> c;
    c = b << 2;
    std::cout << "b << 2:   " << c << '\n';
    c = b >> 2;
    std::cout << "b >> 2:   " << c << '\n';

    b <<= 2;
    std::cout << "b <<= 2:  " << b << '\n';
    b >>= 2;
    cout << "b >>= 2:  " << b << endl << endl;

    bitset<8> d(24);
    cout << "b:        " << b << endl;
    cout << "d:        " << d << endl;

    std::bitset<8> e;
    e = b & d;
    std::cout << "b & d:    " << e << '\n';

    e = b | d;
    std::cout << "b | d:    " << e << '\n';

    e = b ^ d;
    cout << "b ^ d     " << e << endl;

    e = b;
    cout << "~b        " << e << endl;
}
