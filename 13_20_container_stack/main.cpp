#include <iostream>
#include <vector>
#include <stack>

void ausgeben(std::stack<int>& x)
{
    while(!x.empty())
    {
        std::cout << x.top() << " ";
        x.pop();
    }
    std::cout << '\n';
}

int main()
{
    std::stack<int> s;
    for(int i=0; i<5; i++)
        s.push(10 * (i+1));
    std::cout << "push():   ";
    ausgeben(s);

    std::vector v {16,15,14};
    std::stack sd {v};

    std::cout << "Deduktion:";
    while(!sd.empty())
    {
        std::cout << sd.top() << " ";
        sd.pop();
    }
    std::cout << '\n';
}
