#include <iostream>
#include <vector>
using namespace std;

void ausgeben(std::vector<int>& x)
{
    std::vector<int>::iterator position;
    for(position = x.begin(); position != x.end(); position++)
    {
        std::cout << *position << " ";
    }
    std::cout << '\n';
}

int main()
{
    std::vector<int> v;
    std::vector<int>::iterator position;

    v.resize(3);
    for(int i = 0; i<v.size(); i++)
    {
        v.at(i) = 10 * (i+1);
    }
    std::cout << "at()           ";
    ausgeben(v);

    for(int i = 0; i<3; i++)
        v.push_back(4 * (i+1));
    std::cout << "push_back()    ";
    ausgeben(v);

    v.pop_back();
    std::cout << "pop_back():    ";
    ausgeben(v);

    std::cout << "insert():      ";
    position = v.begin() + 1;
    if(position >= v.begin() && position < v.end())
    {
        v.insert(position,77);
        ausgeben(v);
    }
    else
        std::cout << "Position nicht im vector-Feld" << '\n';

    std::cout << "erase():       ";
    position = v.end() - 2;
    if(position >= v.begin() && position < v.end())
    {
        v.erase(position);
        ausgeben(v);
    }
    else
        std::cout << "Position nicht im vector-Feld" << '\n';

    v.clear();
    std::cout << "clear():   ";
    ausgeben(v);

    v = {19, 18, 17};
    std::cout << "Neue Werte:    ";
    ausgeben(v);

    std::vector vd{16,15,14};
    std::cout << "Deduktion:    ";
    ausgeben(v);

}
