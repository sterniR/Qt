#include <iostream>
#include <array>
using namespace std;
void ausnahme()
{
    array<double,3>preise;

    preise.at(0) = 1.45;
    preise.at(1) = 0.85;
    preise.at(2) = 0.75;

    try
    {
        cout << "Element 2 mit []: " << preise[2] << endl;
        cout << "Element 2 mit at(): " << preise.at(2) << endl;
        cout << "Element 5 mit []: " << preise[5] << endl;
        cout << "Element 5 mit at(): " << preise.at(5) << endl;
        cout << "Ende des try-Blocks" << endl;
    }
    catch(exception& e)
    {
        cout << "Fehler: " << e.what() << endl;
    }

    cout << "Nach der Ausnahmebehandlung" << endl;

}
