#include <algorithm>
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

dsatzTyp::dsatzTyp(string vFeld)
{
    std::vector<dsatzTyp> pFeld;

}

void dsatzTyp::ausgeben()
{
    std::cout << name << " " << zeit << '\n';
}

void dsatzTyp::ausgeben_csv(ofstream& td)
{
    std::stringstream nameStrom;
    nameStrom << name;
    std::string nameX = nameStrom.str();
    std::replace(nameX.begin(), nameX.end(), '.', ',');

    td << name << ";" << zeit << endl;
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
    mt19937 z;
    z.seed(system_clock::now().time_since_epoch().count());
    time_point<system_clock> beginn = system_clock::now();
    std::string nameScore;
    std::ofstream textDatei{"/home/roman/Documents/Qt/u_zeit_csv.csv"};
    if(!textDatei)
    {
        std::cout << "error file\n";
        return 1;
    }

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
    if(zaehler == 5)
        cout << " in " << differenz(beginn) << " sec." << endl;
    else
        cout << endl;


    std::cout << "Name: ";
    std::getline(std::cin, nameScore);

    std::vector<dsatzTyp> pFeld;
    pFeld.push_back(dsatzTyp{nameScore, differenz(beginn)});


}
