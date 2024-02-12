#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <bits/stdc++.h>

class personTyp
{
private:
    std::string name;
    std::string nachname;
    std::string geburtstag;
    double gehalt;
    int personalnummer;
public:
    void eingabe();
    void werteZuweisen(const std::string&, const std::string&, const std::string&, const double&, const int&);
    //void werteZuweisen(const std::string&, const std::string&, const std::string&, const double&, const int&);
    static bool weiter();
    static void ausgabeTabelle(const std::vector<personTyp>&);
};

bool personTyp::weiter()
{
    bool check;
    check = false;
    std::string p;

    do
    {
        std::cout << "Datensatz eingeben (J/N): ";
        getline(std::cin, p);
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

void personTyp::werteZuweisen(const std::string& n, const std::string& nn, const std::string& gt, const double& g, const int& pn)
{
    name = n;
    nachname = nn;
    geburtstag = gt;
    gehalt = g;
    personalnummer = pn;
}

void personTyp::eingabe()
{
    std::string nameEingabe;
    std::string nachnameEingabe;
    std::string geburtstagEingabe;
    double gehaltEingabe;
    int personalnummerEingabe;
    std::string eingabe;
    std::istringstream EingabeStrom;

    std::cout << "Name: ";
    std::getline(std::cin, nameEingabe);
    std::cout << '\n';

    std::cout << "Nachname: ";
    std::getline(std::cin, nachnameEingabe);
    std::cout << '\n';

    std::cout << "Geburtstag: ";
    std::getline(std::cin, geburtstagEingabe);
    while (geburtstagEingabe == "" || geburtstagEingabe.size() != 10 || geburtstagEingabe.at(2) != '.' || geburtstagEingabe.at(5) != '.' )
    {
        std::cout << "Geburtstag: ";
        std::getline(std::cin, geburtstagEingabe);
    }
    std::cout << '\n';

    std::cout << "Gehalt: ";
    std::getline(std::cin, eingabe);
    if(eingabe == "")
        gehaltEingabe = 0.0;
    else
    {
        if(eingabe.length() >= 10)
        {
            eingabe.erase(10);
        }
        EingabeStrom.str(eingabe);
        EingabeStrom >> gehaltEingabe;
        EingabeStrom.clear();
    }
    std::cout << '\n';

    std::cout << "Personalnummer (Max. 5 Ziffern): ";
    std::getline(std::cin, eingabe);
    if(eingabe == "")
        personalnummerEingabe = 0.0;
    else
    {
        if(eingabe.length() >= 5)
        {
            eingabe.erase(5);
        }
        EingabeStrom.str(eingabe);
        EingabeStrom >> personalnummerEingabe;
        EingabeStrom.clear();
    }
    std::cout << '\n';

    personTyp::werteZuweisen(nameEingabe, nachnameEingabe, geburtstagEingabe, gehaltEingabe, personalnummerEingabe);
}

void personTyp::ausgabeTabelle(const std::vector<personTyp>& pFeld)
{
    std::cout << std::left
         << std::setw(16) << "Name"
         << std::setw(20) << "Nachname"
         << std::right
         << std::setw(15) << "Personalnummer"
         << std::setw(15) << "Gehalt"
         << std::setw(15) << "Geburtsdatum" << '\n';

    for(const personTyp& p : pFeld)
    //for(int i=0; i<p.at(0).name.size();i++)
        std::cout << std::left << std::fixed << std::setprecision(2)
                  << std::setw(16) << p.name.substr(0, 15)
                  << std::setw(18) << p.nachname.substr(0, 15)
             << std::right
                  << std::setw(17) << p.personalnummer
                  << std::setw(15) << p.gehalt
                  << std::setw(15) << p.geburtstag << std::endl;
    std::cout << std::endl;
}

int main()
{
    std::vector<personTyp> personFeld;
    personTyp personNeu;

    while(personTyp::weiter())
    {
        personNeu.eingabe();
        personFeld.push_back(personNeu);
    }
    if(personFeld.empty())
        return 0;
    personTyp::ausgabeTabelle(personFeld);
}
