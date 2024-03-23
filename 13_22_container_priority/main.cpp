#include <vector>
#include <queue>
#include <iostream>

void ausgeben(std::priority_queue<int>& x)
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
    std::priority_queue<int> p;
    p.push(50);
    p.push(80);
    p.push(10);
    p.push(60);
    p.push(20);

    std::cout << "Push:" << std::endl;
    ausgeben(p);

    std::vector v{26, 22, 28, 20};
    std::queue pd{v};

    /*std::cout << "Deduktion:" << std::endl;
    std::cout << pd.top() << std::endl;
    pd.pop();*/
}
