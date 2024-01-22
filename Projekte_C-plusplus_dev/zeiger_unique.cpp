#include <iostream>
#include <memory>
using namespace std;

void zeiger_unique()
{
    unique_ptr<int> zi(new int);
    *zi = 42;
    cout << "Variable: " << *zi << endl;

    int anzahl;
    cout << "Anzahl der Elemente: ";
    cin >> anzahl;

    unique_ptr<int[]> zfeld(new int[anzahl]);
    cout << "Werte: ";
    for(int i = 0; i<anzahl; i++)
    {
        zfeld[i] = 10 * i;
        cout << zfeld[i] << " ";
    }
    cout << endl;
}
