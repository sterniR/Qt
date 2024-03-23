#include <queue>
#include <vector>
#include <iostream>

void ausgeben(std::queue<int>& x)
{
    while(!x.empty())
    {
        std::cout << x.front() << " ";
        x.pop();
    }
    std::cout << '\n';

}

int main()
{
    std::queue<int> q;
    q.push(50);
    q.push(80);
    q.push(10);
    q.push(60);
    q.push(20);

    std::cout << "Push:   ";
    ausgeben(q);

    std::vector v{26,22,28,20};
    std::queue qd{v};

    std::cout << '\n' << "Deduktion:   \n";
    std::cout << qd.front() << "..." << qd.back() << '\n';
    // qd.pop();
}
