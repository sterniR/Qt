#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    std::bitset<8> b(12);
    std::cout << "Index: ";
    for(int i=b.size()-1; i >=0; i--)
        std::cout << i;
    std::cout << '\n';

    std::cout << "Werte: ";
    for(int i=b.size()-1; i >=0; i--)
        std::cout << b.test(i);
    std::cout << '\n';

    b.set(0);
    std::cout << "set(): ";
    std::cout << b << '\n';

    b.flip(0);
    b.flip(1);
    std::cout << "flip():";
    std::cout << b << '\n';

    b.reset(1);
    std::cout << "reset()";
    std::cout << b << '\n' << '\n';

    cout << "all():      " << b.all() << endl;
    cout << "any():      " << b.any() << endl;
    cout << "none():     " << b.none() << endl;
    cout << "count():    " << b.count() << endl;
}
