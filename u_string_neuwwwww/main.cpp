#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
int main()
{
    vector<string> name;
    vector<string> nachname;
    vector<string> geburtsdatum;
    vector<double> gehalt;
    vector<int> personalnummer;

    string weiter, eingabe;
    int eingabeInt;
    double eingabeDouble;
    istringstream eingabeStrom;

    do
    {
        cout << "Datensatz eingeben (J/N): ";
        getline(cin, weiter);
    }
    while(weiter != "J" && weiter != "N");

    while(weiter == "J")
    {
        cout << "Name: ";
        getline(cin, eingabe);
        name.push_back(eingabe);

        cout << "Nachname: ";
        getline(cin, eingabe);
        nachname.push_back(eingabe);

        cout << "Personalnummer: ";
        getline(cin, eingabe);
        if(eingabe == "")
        {
            eingabeInt = 0;
        }
        else
        {
            eingabeStrom.str(eingabe);
            eingabeStrom >> eingabeInt;
            eingabeStrom.clear();
        }
        personalnummer.push_back(eingabeInt);


        cout << "Gehalt: ";
        getline(cin, eingabe);

        if(eingabe == "")
        {
            eingabeDouble = 0;
        }
        else
        {
            eingabeStrom.str(eingabe);
            eingabeStrom >> eingabeDouble;
            eingabeStrom.clear();

        }
        gehalt.push_back(eingabeDouble);


        do
        {
            cout << "Geburtsdatum: (Format: TT.MM.JJJJ)";
            getline(cin, eingabe);
        }
        while(eingabe.length() != 10 || eingabe.at(2) != '.' ||  eingabe.at(5) != '.');
        geburtsdatum.push_back(eingabe);


        do
        {
            cout << "Datensatz eingeben (J/N): ";
            getline(cin, weiter);
        }
        while(weiter != "J" && weiter != "N");
    }
    if(name.empty())
        return 0;

    cout << fixed << setprecision(2);
    cout << left << setw(15) << "Name" << setw(15) << "Nachname" << right << setw(15) << "Personalnummer" << setw(15) << "Gehalt" << setw(15) << "Geburtdatum" << endl;

    for(int i = 0; i < name.size(); i++)
        cout << left
             << setw(15) << name.at(i) << setw(15) << nachname.at(i) << right << setw(15) << personalnummer.at(i) << setw(15) << gehalt.at(i) << setw(15) << geburtsdatum.at(i) << endl;
}
