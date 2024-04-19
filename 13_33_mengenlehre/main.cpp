<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <algorithm>

void ausgeben(std::vector<int>& x)
{
    for(auto p : x)
        std::cout << p << " ";
=======
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void ausgeben(std::vector<int>& x)
{
    for(auto p : x)
    {
        std::cout << p << " ";
    }
>>>>>>> c1964a8aff16446b735f13ab625f643551a89f49
    std::cout << '\n';
}

int main()
{
    std::vector<int> va{3, 18, 5, 17, 12};
    std::vector<int> vb{19, 3, 8, 17};
    std::vector<int> v1, v2, v3, v4, v5;

    sort(va.begin(), va.end());
<<<<<<< HEAD
    std::cout << "Menge A:    ";
    ausgeben(va);

    sort(vb.begin(), vb.end());
    std::cout << "Menge B:    ";
    ausgeben(vb);

    merge(va.begin(), va.end(), vb.begin(), vb.end(), inserter(v1, v1.begin()));
    std::cout << "merge():    ";
    ausgeben(v1);

=======
    cout << "Menge A:      ";
    ausgeben(va);

    sort(vb.begin(), vb.end());
    cout << "Menge B:      ";
    ausgeben(vb);

    merge(va.begin(), va.end(), vb.begin(), vb.end(), inserter(v1, v1.begin()));
    cout << "merge():      ";
    ausgeben(v1);

    if(includes(v1.begin(), v1.end(), va.begin(), va.end()))
        cout << "includes:     Ja    " << endl;
    cout << endl;

    set_intersection(va.begin(), va.end(), vb.begin(), vb.end(), inserter(v2, v2.begin()));
    cout << "set_inter...: ";
    ausgeben(v2);

    set_union(va.begin(), va.end(), vb.begin(), vb.end(), inserter(v3, v3.begin()));
    cout << "set_union():  ";
    ausgeben(v3);

    set_difference(va.begin(), va.end(), vb.begin(), vb.end(), inserter(v4, v4.begin()));
    cout << "set_different() ";
    ausgeben(v4);

    set_symmetric_difference(va.begin(), va.end(), vb.begin(), vb.end(), inserter(v5, v5.begin()));
    cout << "set_symmetric_difference(): ";
    ausgeben(v5);
>>>>>>> c1964a8aff16446b735f13ab625f643551a89f49
}
