#include <iostream>

using namespace std;

int main()
{
    int n1 = 0, n2 = 1, f, n0 = 1;

    for(int i =2; i <= 20; i++) {
        f = n1 + n2;
        n1 = n2;
        n2 = n1;
        cout << i << "st: " << f << endl;
    }
}
