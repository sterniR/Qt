#include <iostream>
#include <regex>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;


int main()
{

    string checker, eingabe, ausgabe, sleer = "0";
    string tag, monat, jahr;
    int inttag, intmonat, intjahr;
    string name, vorname;
    vector<string> vname, vvorname, vpersonalnummer, vgehalt, vgeburt;
    int vsize = 0;
    istringstream eingabeStrom;
    ostringstream ausgabeStrom;
    int datumChecker = 0;
    int jahrChecker = 0;
    int schaltjahr = 0;
    string punkt = ".";
    string leerzeichen = " ";

    cout << "Datensatz eingeben (J/N): ";
    getline(cin, checker);
    do {
        if (checker != "J") {
            cout << "Datensatz eingeben (J/N): ";
            getline(cin, checker);
        }
        else if(checker == "J") {
            cout << "Nachname: ";
            getline(cin, eingabe);
            if(eingabe == "")
            {
                vname.push_back(sleer);
            }
            else
            {
                eingabeStrom.str(eingabe);
                eingabeStrom >> name;
                eingabeStrom.clear();
                vname.push_back(name);
            }
            cout << "Vorname: ";
            getline(cin, eingabe);
            if(eingabe == "")
            {
                vvorname.push_back(sleer);
            }
            else
            {
                eingabeStrom.str(eingabe);
                eingabeStrom >> vorname;
                eingabeStrom.clear();
                vvorname.push_back(vorname);
            }
            cout << "Personalnummer: ";
            getline(cin, eingabe);
            if(eingabe == "")
            {
                vpersonalnummer.push_back(sleer);
            }
            else
            {
                ausgabeStrom.str("");
                ausgabeStrom << eingabe;
                ausgabe = ausgabeStrom.str();
                ausgabeStrom.clear();
                if(regex_match(ausgabe, regex("[0-9]+"))) {
                    vpersonalnummer.push_back(ausgabe);
                }
                else {
                    vpersonalnummer.push_back(sleer);
                }
            }
            cout << "Gehalt (Nur mit 2 Nachkommastellen): ";
            getline(cin, eingabe);
            if(eingabe == "")
            {
                vgehalt.push_back(sleer);
            }
            else
            {
                    ausgabeStrom.str("");
                    ausgabeStrom << eingabe;
                    ausgabe = ausgabeStrom.str();
                    ausgabeStrom.clear();
                    if(regex_match(ausgabe, regex("[0-9]+[.][0-9]{1,2}"))) {
                        vgehalt.push_back(ausgabe);
                        //break;
                    }
                    else {
                        //checkerRegex++;
                        vgehalt.push_back(sleer);
                    }
            }

            do {
                cout << "Geburtstag: ";
                getline(cin, eingabe);
                if(eingabe == "")
                {
                    vgeburt.push_back(sleer);
                }
                else
                {
                    do {

                    }
                    while(jahrChecker == 1);
                    ausgabeStrom.str("");
                    ausgabeStrom << eingabe;
                    ausgabe = ausgabeStrom.str();
                    ausgabeStrom.clear();
                    if(regex_match(ausgabe, regex("[0-9]{1,2}[.][0-9]{1,2}[.][0-9]{4}")))
                    {
                        int start = 0;
                        int a = 0;
                        for(int i = 0; i < ausgabe.size(); i++)
                        {
                            if(ausgabe.at(i) == '.')
                            {
                                a++;
                                if(a == 1)
                                {
                                    tag = ausgabe.substr(start, i-start);
                                    inttag = stoi(tag);
                                }
                                else if(a == 2)
                                {
                                    monat = ausgabe.substr(start, i-start);
                                    intmonat = stoi(monat);
                                }
                                start = i+1;
                            }
                        }
                        jahr = ausgabe.substr(start, ausgabe.size());
                        intjahr = stoi(jahr);
                        //cout << inttag << " " << intmonat << " " << intjahr << " " << endl;


                        if(intjahr % 4 == 0 && intjahr % 100 == 0)
                        {
                            if(intjahr % 400 == 0)
                            {
                                cout << "Schaltjahr" << endl;
                                schaltjahr = 1;
                            }
                            else
                            {
                                cout << "No Schaltjahr" << endl;
                                schaltjahr = 0;
                            }
                        }
                        else if(intjahr % 4 == 0)
                        {
                            cout << "Schaltjahr" << endl;
                            schaltjahr = 1;
                        }
                        else
                        {
                            cout << "No Schaltjahr" << endl;
                            schaltjahr = 0;
                        }

                        switch (intmonat) {
                        case 1:
                        case 3:
                        case 5:
                        case 7:
                        case 8:
                        case 10:
                        case 12:
                            if(inttag <= 31)
                            {
                                ausgabeStrom.str("");
                                ausgabeStrom << inttag;
                                ausgabe = ausgabeStrom.str();
                                ausgabeStrom.clear();
                                vgeburt.push_back(ausgabe);
                                vgeburt.push_back(punkt);

                                ausgabeStrom.str("");
                                ausgabeStrom << intmonat;
                                ausgabe = ausgabeStrom.str();
                                ausgabeStrom.clear();
                                vgeburt.push_back(ausgabe);
                                vgeburt.push_back(punkt);

                                ausgabeStrom.str("");
                                ausgabeStrom << intjahr;
                                ausgabe = ausgabeStrom.str();
                                ausgabeStrom.clear();
                                vgeburt.push_back(ausgabe);
                                vgeburt.push_back(leerzeichen);
                                datumChecker = 0;
                            }
                            else
                            {
                                cout << "Falscher Tag  max.31" << endl;
                                datumChecker = 1;
                                break;
                            }
                            break;

                        case 4:
                        case 6:
                        case 9:
                        case 11:

                            if(inttag <= 30)
                            {
                                ausgabeStrom.str("");
                                ausgabeStrom << inttag;
                                ausgabe = ausgabeStrom.str();
                                ausgabeStrom.clear();
                                vgeburt.push_back(ausgabe);
                                vgeburt.push_back(punkt);

                                ausgabeStrom.str("");
                                ausgabeStrom << intmonat;
                                ausgabe = ausgabeStrom.str();
                                ausgabeStrom.clear();
                                vgeburt.push_back(ausgabe);
                                vgeburt.push_back(punkt);

                                ausgabeStrom.str("");
                                ausgabeStrom << intjahr;
                                ausgabe = ausgabeStrom.str();
                                ausgabeStrom.clear();
                                vgeburt.push_back(ausgabe);
                                vgeburt.push_back(leerzeichen);
                                datumChecker = 0;

                            }
                            else
                            {
                                cout << "Falscher Tag max.30" << endl;
                                datumChecker = 1;
                                break;
                            }
                            break;

                        case 2:
                            if(schaltjahr == 1)
                            {

                                if(inttag <= 29)
                                {
                                    ausgabeStrom.str("");
                                    ausgabeStrom << inttag;
                                    ausgabe = ausgabeStrom.str();
                                    ausgabeStrom.clear();
                                    vgeburt.push_back(ausgabe);
                                    vgeburt.push_back(punkt);

                                    ausgabeStrom.str("");
                                    ausgabeStrom << intmonat;
                                    ausgabe = ausgabeStrom.str();
                                    ausgabeStrom.clear();
                                    vgeburt.push_back(ausgabe);
                                    vgeburt.push_back(punkt);

                                    ausgabeStrom.str("");
                                    ausgabeStrom << intjahr;
                                    ausgabe = ausgabeStrom.str();
                                    ausgabeStrom.clear();
                                    vgeburt.push_back(ausgabe);
                                    vgeburt.push_back(leerzeichen);
                                    datumChecker = 0;
                                }
                                else
                                {
                                    cout << "Falscher Tag max.29" << endl;
                                    datumChecker = 1;
                                    break;
                                }
                            }
                            else if(schaltjahr == 0)
                            {
                                if(inttag <= 28)
                                {
                                    ausgabeStrom.str("");
                                    ausgabeStrom << inttag;
                                    ausgabe = ausgabeStrom.str();
                                    ausgabeStrom.clear();
                                    vgeburt.push_back(ausgabe);
                                    vgeburt.push_back(punkt);

                                    ausgabeStrom.str("");
                                    ausgabeStrom << intmonat;
                                    ausgabe = ausgabeStrom.str();
                                    ausgabeStrom.clear();
                                    vgeburt.push_back(ausgabe);
                                    vgeburt.push_back(punkt);

                                    ausgabeStrom.str("");
                                    ausgabeStrom << intjahr;
                                    ausgabe = ausgabeStrom.str();
                                    ausgabeStrom.clear();
                                    vgeburt.push_back(ausgabe);
                                    vgeburt.push_back(leerzeichen);
                                    datumChecker = 0;
                                }
                                else
                                {
                                    cout << "Falscher Tag max.28" << endl;
                                    datumChecker = 1;
                                    break;
                                }
                            }
                            else
                            {
                                cout << "Falscher Tag x" << endl;
                                datumChecker = 1;
                                break;
                            }
                            break;

                        default:
                            cout << "Falscher Monat max.12" << endl;
                            datumChecker = 1;
                            break;
                        }
                    }
                    else {
                        datumChecker = 1;
                    }
                }
            }
            while (datumChecker == 1);
            cout << "Datensatz eingeben (J/N): ";
            getline(cin, checker);
        }
    }
    while(checker == "J" || checker != "N");

    cout << left;
    cout << setw(15) << "Name" << setw(15) << "Vorname" << setw(15) << "Personalnummer" << setw(15) << "Gehalt" << setw(15) << "Geburtstag" << endl;

    vsize = vgehalt.size();

    int num = 0;
    for (int i = 0; i < vsize; i++) {
        cout << left;
        cout << fixed << setw(15) << vname.at(i);
        cout << fixed << setw(15) << vvorname.at(i);
        cout << fixed << setw(15) << vpersonalnummer.at(i);
        cout << fixed << setprecision(2) << setw(15) << vgehalt.at(i);

        for(int d = 0; d < vgeburt.size(); d++)
        {
            cout << vgeburt.at(num);
            num++;
            if(vgeburt.at(num) == " ")
            {
                num++;
                break;
            }
        }
        cout << endl;
    }
}

