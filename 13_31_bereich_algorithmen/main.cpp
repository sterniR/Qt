#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>

using namespace std;

void ausgeben(vector<int>& x)
{
    for(auto i : x)
        std::cout << i << " ";
    std::cout << '\n';
}

void ausgebenZahl(const int& z)
{
    std::cout << z << " ";
}

int main()
{
    std::vector<int> v{12,27,5,27,16,9,14};

    std::cout << "for_each():   ";
    for_each(v.begin(), v.end(), ausgebenZahl);
    std::cout << '\n';



    std::cout << "Mit Lambda:   ";
    for_each(v.begin(), v.end(), [](int z){std::cout << z << " ";});
    std::cout << '\n';

    /*int x = 4;
    auto y = [&r = x, b = x+1]()->int {
        r += 2;
        return b + 2;
    }();  // Updates ::x to 6, and initializes y to 7.*/

    if(find(v.begin(), v.end(), 27) != v.end())
    std::cout << "find()27:     Ja\n";

    std::cout << "count()27:    " << count(v.begin(), v.end(), 27) << '\n';

    std::cout << "count_if():   " <<
        count_if(v.begin(), v.end(),[](int z){return z % 2 == 0;}) << '\n';
}