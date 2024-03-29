#include <iostream>
#include <set>
#include <random>
#include <chrono>
using namespace std;

void ausgebenRange(std::set<int>& x)
{
    for(auto i : x) //     for(auto i : x)
        std::cout << i << " ";
    std::cout << '\n';
}

int main()
{
    std::set<int> s;

    std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::cout << "insert():    ";
    for(int i=0; i<8;i++)
    {
        int z = gen() % 6 + 1;
        std::cout << z << " ";
        s.insert(z);
    }
    std::cout << '\n';
    std::cout << "set:         ";
    ausgebenRange(s);

    std::cout << "count():     " << s.count(6) << '\n';

    if(s.find(3) != s.end())
        cout << "find():      3" << endl;

    if(s.contains(3))
        cout << "contains():  3" << endl;

    std::set<int>::iterator pos;
    pos = s.lower_bound(6);
    if( pos != s.end())
        std::cout << "lower_bound(): " << *pos << '\n';
    pos = s.upper_bound(1);
    if( pos != s.end())
        std::cout << "upper_bound(): " << *pos << '\n';

    s.erase(3);
    s.erase(4);
    std::cout << "erase():     ";
    ausgebenRange(s);

    s.clear();
    std::cout << "clear():     ";
    ausgebenRange(s);

    std::set sd{6,1,2,6,3};
    std::cout << "Liste:       ";
    ausgebenRange(sd);

    std::set sa{4,3,6};

    sd.merge(sa);
    std::cout << "merge()(s):  ";
    ausgebenRange(sd);

    std::cout << "merge()(sa): ";
    ausgebenRange(sa);
}
