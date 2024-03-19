#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

class dsatzTyp
{
private:
    string name;
    double zeit;
public:
    dsatzTyp(string, double);
    dsatzTyp(string);
    void ausgeben();
    void ausgeben_csv(ofstream&);
    bool operator > (const dsatzTyp&);
};

dsatzTyp::dsatzTyp(string n, double z)
{
    name = n;
    zeit = z;
}

dsatzTyp::dsatzTyp(string ganzeZeile)
{

    replace(ganzeZeile.begin(), ganzeZeile.end(), ';', ' ');
    std::istringstream zeilenStrom(ganzeZeile);

    zeilenStrom >> name;

    zeilenStrom >> zeit;

}

void dsatzTyp::ausgeben()
{
    cout << zeit << " sec. " << name << endl;
}

void dsatzTyp::ausgeben_csv(ofstream& td)
{
    std::stringstream nameStrom;
    nameStrom << name;
    std::string nameX = nameStrom.str();
    std::replace(nameX.begin(), nameX.end(), '.', ',');

    td << name << ";" << zeit << endl;
}

bool dsatzTyp::operator> (const dsatzTyp& zeitObjekt)
{
    if(zeit > zeitObjekt.zeit)
        return true;
    else
        return false;
}

int eingabe()
{
    string ein;
    int zahl;
    istringstream strom;

    getline(cin, ein);
    if(ein == "")
        zahl = 0;
    else
    {
        strom.str(ein);
        strom >> zahl;
        strom.clear();
    }
    return zahl;
}

double differenz(time_point<system_clock> beginn)
{
    time_point<system_clock> ende = system_clock::now();
    duration<double> dauer = ende - beginn;
    return dauer.count();
}


int main()
{
    int a, b, c, zaehler = 0;
    float zeitMessung;
    mt19937 z;
    z.seed(system_clock::now().time_since_epoch().count());
    time_point<system_clock> beginn = system_clock::now();


    for(int i=0; i<5; i++)
    {
        a = z() % 20 + 20;
        b = z() % 20 + 20;
        c = a + b;
        cout << "Aufgabe " << i+1 << ": " << a << " + " << b << " = ";
        if(eingabe() == c)
            zaehler++;
    }

    cout << "Richtig: " << zaehler << " von 5";
    cout << " in " << differenz(beginn)  << " sec." << endl;
    zeitMessung = differenz(beginn);

    std::string nameScore;
    std::ofstream textDatei{"/home/roman/Documents/Qt/u_zeit_csv.csv", std::ios::app};
    if(!textDatei)
    {
        std::cout << "error file\n";
        return 1;
    }

    std::cout << "Name: ";
    std::getline(std::cin, nameScore);
    dsatzTyp highscoreNeu{nameScore, zeitMessung};
    highscoreNeu.ausgeben_csv(textDatei);

    std::ifstream textDateiInput{"/home/roman/Documents/Qt/u_zeit_csv.csv"};
    if(!textDatei)
    {
        std::cout << "error file\n";
        return 1;
    }
    std::vector<dsatzTyp> pFeld;
    while(textDateiInput)
    {
        string zeile;
        getline(textDateiInput, zeile);
        if(!textDateiInput)
            break;
        pFeld.push_back(zeile);
    }

    bool sortiert;
    do
    {
        sortiert = true;
        for(int i=0; i<pFeld.size()-1; i++)
        {
            if(pFeld.at(i) > pFeld.at(i+1))
            {
                sortiert = false;
                dsatzTyp p = pFeld.at(i);
                pFeld.at(i) = pFeld.at(i+1);
                pFeld.at(i+1) = p;
            }
        }
    }
    while(!sortiert);

    cout << fixed << setprecision(2);
    std::cout << "Bestzeiten: \n";
    for(dsatzTyp& p : pFeld)
    {
        p.ausgeben();
    }
}
