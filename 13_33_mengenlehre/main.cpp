#include <iostream>
#include <vector>
#include <algorithm>

void ausgeben(std::vector<int>& x)
{
    for(auto p : x)
        std::cout << p << " ";
    std::cout << '\n';
}

int main()
{
    std::vector<int> va{3, 18, 5, 17, 12};
    std::vector<int> vb{19, 3, 8, 17};
    std::vector<int> v1, v2, v3, v4, v5;

    sort(va.begin(), va.end());
    std::cout << "Menge A:    ";
    ausgeben(va);

    sort(vb.begin(), vb.end());
    std::cout << "Menge B:    ";
    ausgeben(vb);

    merge(va.begin(), va.end(), vb.begin(), vb.end(), inserter(v1, v1.begin()));
    std::cout << "merge():    ";
    ausgeben(v1);

}
