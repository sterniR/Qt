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
            if(eingabe.length() >= 7)
            {
                eingabe.erase(7);
            }
            eingabeStrom.str(eingabe);
            eingabeStrom >> eingabeInt;
            eingabeStrom.clear();

        }
        personalnummer.push_back(eingabeInt);


        cout << "Gehalt: ";
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

        gehalt.push_back(eingabeDouble);


        cout << "Geburtstag: ";
        getline(cin, eingabe);

        while (eingabe == "" || eingabe.size() != 10 || eingabe.at(2) != '.' || eingabe.at(5) != '.' ){
            cout << "Geburtstag: ";
            getline(cin, eingabe);
        }
        geburtsdatum.push_back(eingabe);

        do
        {
            cout << "Datensatz eingeben (J/N): ";
            getline(cin, weiter);
        }
        while(weiter != "J" && weiter != "N");

        if (weiter == "J")
        {
            continue;
        }
        else;
        {
            break;
        }

    }

    cout << left
         << setw(16) << "Name"
         << setw(20) << "Nachname"
         << right
         << setw(15) << "Personalnummer"
         << setw(15) << "Gehalt"
         << setw(15) << "Geburtsdatum" << endl;

    for(int i = 0; i<name.size(); i++)
    {
             cout << left
             << setw(16) << name.at(i).substr(0, 15)
             << setw(18) << nachname.at(i).substr(0, 15)
             << right
             << setw(17) << personalnummer.at(i)
             << setw(15) << fixed << setprecision(2) << gehalt.at(i)
             << setw(15) << geburtsdatum.at(i) << endl;
        cout << endl;
    }


}
