#include <iostream>
#include <memory>

using namespace std;

int main()
{
    unique_ptr<int> zi(new int);
    *zi = 42;
    cout << *zi << endl;

    int anzahl;
    cout << "Anzahl der Elemente: " << endl;
    cin >> anzahl;

    unique_ptr<int[]> zfeld(new int[anzahl]);
    cout << "Werte: ";
    for(int i=0; i<anzahl; i++)
    {
        zfeld[i] = 10 * i;
        cout << zfeld[i] << " ";
    }
    cout << endl;
}
