#include <iostream>

char big[1024*1024*1024];

int numGenerator () {
    static int i = 0;
    big[i] = 4;
    ++i;
    return i;
}

class staticMember {
public:
    static int zahlMore;
};

int staticMember::zahlMore = 1;


int main()
{
    std::cout << numGenerator() << '\n';
    std::cout << numGenerator() << '\n';
    std::cout << numGenerator() << '\n' << '\n';

    staticMember::zahlMore = 2;
    std::cout << staticMember::zahlMore << '\n';
}
