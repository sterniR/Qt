#include <iostream>
#include <string>
using namespace std;


    struct pTyp
    {
        int anzahl;
        double preis;
        string bezeichnung;
    };


int main()
{
        pTyp pEins;

        pEins.anzahl = 8;
        pEins.preis = 1.49;
        pEins.bezeichnung = "Birne";

        cout << pEins.anzahl << " " << pEins.bezeichnung << " fuer/pro Stueck " << pEins.preis << endl;
}
