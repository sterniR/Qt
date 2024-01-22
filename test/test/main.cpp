#include <iostream>
#include <array>
using namespace std;

int main()
{
    double aFeld0, aFeld1, aFeld2, aFeld3, aFeld4;

    array<int,5> aFeld;

    cout << "Eingabe 1. Zahl: ";
    cin >> aFeld0;
    cout << "Eingabe 2. Zahl: ";
    cin >> aFeld1;
    cout << "Eingabe 3. Zahl: ";
    cin >> aFeld2;
    cout << "Eingabe 4. Zahl: ";
    cin >> aFeld3;
    cout << "Eingabe 5. Zahl: ";
    cin >> aFeld4;

    aFeld.at(0) = aFeld0;
    aFeld.at(1) = aFeld1;
    aFeld.at(2) = aFeld2;
    aFeld.at(3) = aFeld3;
    aFeld.at(4) = aFeld4;

    cout << "Feld in umgekehrter Reihenfolge:" << endl;

    for(int i=4; i<aFeld.size(); i--)
        cout << aFeld.at(i) << endl;
}
