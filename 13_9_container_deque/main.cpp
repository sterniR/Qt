#include <iostream>
#include <deque>
using namespace std;

void ausgeben(std::deque<int>& x)
{
    std::deque<int>::iterator position;
    for(position = x.begin(); position != x.end(); position++)
        std::cout << *position << " ";
    std::cout << '\n';

}

int main()
{
    std::deque<int> d;
    std::deque<int>::iterator position;

    for(int i=0; i<3; i++)
        d.push_back(10 * (i+1));
    std::cout << "push_back:  ";
    ausgeben(d);

    for(int i=0; i<3; i++)
        d.push_front(11 * (i+1));
    std::cout << "push_front: ";
    ausgeben(d);

    std::cout << "front():    " << d.front() << '\n';
    std::cout << "back():     " << d.back() << '\n';

    d.pop_back();
    std::cout << "pop_back(): ";
    ausgeben(d);

    d.pop_front();
    std::cout << "pop_front():";
    ausgeben(d);

    std::cout << "insert():   ";
    position = d.begin() + 1;
    if(position >= d.begin() && position < d.end())
    {
        d.insert(position, 77);
        ausgeben(d);
    }
    else
        std::cout << "Position nicht in der Deque\n";

    std::cout << "erase():    ";
    position = d.end() - 2;
    if(position >= d.begin() && position < d.end())
    {
        d.erase(position);
        ausgeben(d);
    }
    else
        std::cout << "Position nicht in der Deque\n";

    d.resize(d.size() + 1);
    d.at(d.size() - 1) = 99;
    std::cout << "at():       ";
    ausgeben(d);

    d.clear();
    std::cout << "clear():    ";
    ausgeben(d);

    d = {19,18, 17};
    std::cout << "Neue Werte: ";
    ausgeben(d);

    std::deque dd{16,15,14};
    std::cout << "Deduktion:  ";
    ausgeben(dd);
}
