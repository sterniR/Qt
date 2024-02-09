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
    std::string geburtsdatum;
    std::string gehalt;
    std::string personalnummer;
public:
    void ini(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
    static bool weiter();
    friend std::ostream& operator << (std::ostream&, const personTyp&);
    void eingabe();
    void ausgabeTabelle(const std::vector<personTyp>&);
    void Feld(std::vector<personTyp>&);

};

void personTyp::ini(const std::string& n, const std::string& nn, const std::string& gd, const std::string& gh, const std::string& pn)
{
    name = n;
    nachname = nn;
    geburtsdatum = gd;
    gehalt = gh;
    personalnummer = pn;
}

void eingabe()
{
    std::string eingabename;
    std::string eingabenachname;
    std::string eingabegeburtsdatum;
    double eingabegehalt;
    int eingabepersonalnummer;
    std::vector<personTyp> Feld;

    std::cout << "Name: ";
    getline(std::cin, eingabename);

    std::cout << "Nachname: ";
    getline(std::cin, eingabenachname);

    std::cout << "Geburtsdatum: ";
    getline(std::cin, eingabegeburtsdatum);

    std::cout << "Gehalt: ";
    std::cin >> eingabegehalt;
    std::string eingabegehaltString = std::to_string(eingabegehalt); //String

    std::cout << "Personalnummer: ";
    std::cin >> eingabepersonalnummer;
    std::string eingabepersonalnummerString = std::to_string(eingabepersonalnummer); //String

    Feld.at(0).ini(eingabename, eingabenachname, eingabegeburtsdatum, eingabegehaltString, eingabepersonalnummerString);
}

bool weiter(std::string p)
{
    bool check;
    check = false;
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


std::ostream& operator << (std::ostream& om, const personTyp& p)
{
    om << p.name << " " << p.nachname << " " << p.geburtsdatum
        << " " << p.gehalt << " " << p.personalnummer << '\n';
    return om;
}

void ausgabeTabelle(std::vector<personTyp>& Feld)
{
    std::cout << std::left
              << std::setw(16) << "Name"
              << std::setw(20) << "Nachname"
            << std::right
              << std::setw(15) << "Personalnummer"
              << std::setw(15) << "Gehalt"
              << std::setw(15) << "Geburtsdatum" << std::endl;
    for(personTyp &p : Feld)
    {
        std::cout << p << '\n';
    }
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
}
