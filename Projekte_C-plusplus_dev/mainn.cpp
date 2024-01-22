#include <iostream>
#include <array>
#include <memory>
#include <test.cpp>
#include <feld_ausnahme.cpp>
#include <zeiger_unique.cpp>
using namespace std;

int main()
{
    /*------*/
    array<double,3> preise;

    preise.at(0) = 1.45;
    preise.at(1) = 0.85;
    preise.at(2) = 0.75;

    for(size_t i=0; i<preise.size(); i++)
        cout << "Element " << i << ": " << preise.at(i) << endl;

    double summe = 0.0;
    for(const double& p : preise)
        summe += p;
    cout << "Summe: " << summe << endl;

    /*------*/
    func("Hallooo");
    /*------*/

    /*------*/
    unsigned int a = -551;
    cout << a << endl;
    /*------*/

    /*------*/
    ausnahme();
    /*------*/

    /*------*/
    zeiger_unique();
    /*------*/
}
