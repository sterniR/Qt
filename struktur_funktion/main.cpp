#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

typedef struct pTyp
{
    int anzahl;
    string bezeichnugn;
    double preis;
}postenTyp;

void groesseFeld(vector<postenTyp> &feld)
{
    int anzahl;
    string eingabe;
    istringstream eingabeStrom;

    cout << "Anzahl der Rechnungsposten: ";
    getline(cin, eingabe);

    if(eingabe == "")
    {
        cout << "Keine Angabe." << endl;
        anzahl = 0;
    }
    else
    {
        eingabeStrom.str(eingabe);
        eingabeStrom >> anzahl;
        eingabeStrom.clear();
    }

    feld.resize(anzahl);
}

void eingabe(postenTyp &eingabeFeld)
{
    string eingabe;
    int anzahl;
    istringstream eingabeStrom;
    double preis;
    string bezeichnung;

    cout << "Anzahl: ";
    getline(cin, eingabe);

    if(eingabe == "")
    {
        cout << "Keine Angabe." << endl;
        anzahl = 0;
    }
    else
    {
        eingabeStrom.str(eingabe);
        eingabeStrom >> anzahl;
        eingabeStrom.clear();
    }

    eingabeFeld.anzahl = anzahl;

    cout << "Preis: ";
    getline(cin, eingabe);

    if(eingabe == "")
    {
        cout << "Keine Angabe." << endl;
        preis = 0.0;
    }
    else
    {
        eingabeStrom.str(eingabe);
        eingabeStrom >> preis;
        eingabeStrom.clear();
    }

    eingabeFeld.preis = preis;

    cout << "Bezeichnung: ";
    getline(cin, eingabe);

    if(eingabe == "")
    {
        cout << "Keine Angabe." << endl;
        bezeichnung = '0';
    }
    else
    {
        eingabeStrom.str(eingabe);
        eingabeStrom >> bezeichnung;
        eingabeStrom.clear();
    }

    eingabeFeld.bezeichnugn = bezeichnung;

}

void eingabeFeld(vector<postenTyp> &feld)
{
    for(postenTyp &p : feld)
    {
        eingabe(p);
    }
}


void ausgabe(postenTyp &ausgabe)
{
    cout << ausgabe.anzahl << " " << ausgabe.preis << " " << ausgabe.bezeichnugn << endl;

}

void ausgabeFeld(vector<postenTyp> &ausgabeFeld)
{
    for(postenTyp &p : ausgabeFeld)
    {
        ausgabe(p);
    }
}


int main()
{
    vector<postenTyp> pfeld;
    groesseFeld(pfeld);
    eingabeFeld(pfeld);

    cout << "Noch ein Element: " << endl;
    postenTyp pNeu;
    eingabe(pNeu);
    pfeld.push_back(pNeu);

    ausgabeFeld(pfeld);


}
