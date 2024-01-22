#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

typedef struct vStruct
{
    vector<string> name;
    vector<string> nachname;
    vector<string> geburtsdatum;
    vector<double> gehalt;
    vector<int> personalnummer;
}sFrage;

bool weiter1(string p)
{
    bool check;
    check = false;
    do
    {
        cout << "Datensatz eingeben (J/N): ";
        getline(cin, p);
    }
    while(p != "J" && p != "N");
    if(p == "J")
    {
        check = true;
    }
    else
    {
        return check;
    }
    return check;
}

string eingabeString(const string&)
{
    string eingabe;
    getline(cin, eingabe);
    return eingabe;
}

int eingabeInt(const string&)
{
    string eingabe;
    int eingabeInt;
    istringstream eingabeStrom;
    getline(cin, eingabe);
    if(eingabe == "")
    {
        eingabeInt = 0;
    }
    else
    {
        if(eingabe.length() >= 7)
        {
            eingabe.erase(7);
        }
        eingabeStrom.str(eingabe);
        eingabeStrom >> eingabeInt;
        eingabeStrom.clear();
    }
    return eingabeInt;
}

double eingabeDouble(const string&)
{
    string eingabe;
    double eingabeDouble;
    istringstream eingabeStrom;
    getline(cin, eingabe);
    if(eingabe == "")
    {
        eingabeDouble = 0.0;
    }
    else
    {
        if(eingabe.length() >= 10)
        {
            eingabe.erase(10);
        }
        eingabeStrom.str(eingabe);
        eingabeStrom >> eingabeDouble;
        eingabeStrom.clear();
    }
    return eingabeDouble;
}

string eingabeDatum(const string&)
{
    string eingabe;
    istringstream eingabeStrom;
    getline(cin, eingabe);

    while (eingabe == "" || eingabe.size() != 10 || eingabe.at(2) != '.' || eingabe.at(5) != '.' ){
        cout << "Geburtstag: ";
        getline(cin, eingabe);
    }
    return eingabe;
}

void ausgabe(const sFrage& p)
{
    for(int i=0; i<p.name.size();i++)
        cout << left << fixed << setprecision(2)
             << setw(16) << p.name.at(i).substr(0, 15)
             << setw(18) << p.nachname.at(i).substr(0, 15)
             << right
             << setw(17) << p.personalnummer.at(i)
             << setw(15) << p.gehalt.at(i)
             << setw(15) << p.geburtsdatum.at(i) << endl;
    cout << endl;
}

void ausgabeTabelle(const sFrage& feld)
{

    cout << left
         << setw(16) << "Name"
         << setw(20) << "Nachname"
         << right
         << setw(15) << "Personalnummer"
         << setw(15) << "Gehalt"
         << setw(15) << "Geburtsdatum" << endl;

        ausgabe(feld);

}

int main()
{
    sFrage personTyp;
    string weiter, eingabe;

    while(weiter1(weiter) == true)
    {
        cout << "Name: ";
        personTyp.name.push_back(eingabeString(eingabe));

        cout << "Nachname: ";
        personTyp.nachname.push_back(eingabeString(eingabe));

        cout << "Personalnummer: ";
        personTyp.personalnummer.push_back(eingabeInt(eingabe));

        cout << "Gehalt: ";
        personTyp.gehalt.push_back(eingabeDouble(eingabe));

        cout << "Geburtstag: ";
        personTyp.geburtsdatum.push_back(eingabeDatum(eingabe));
    }

    ausgabeTabelle(personTyp);
}
