#include <iostream>
#include <cstdlib>
#include <ctime>
#include <regex>
#include <string>
#include <sstream>
using namespace std;

int eingabeZahl(string eingabeWert)
{
    int intWert ;

    if(regex_match(eingabeWert, regex("^\\d*$")))
    {
        intWert = true;
    }
    else
    {
        intWert = false;
    }
    return intWert;
}


int main()
{
    int a, b, c, zaehler = 0;
    string wert, cWert;
    srand((unsigned int)time(nullptr));

    for(int i=0; i<5; i++)
    {
        a = rand() % 20 + 20;
        b = rand() % 20 + 20;
        c = a + b;

        ostringstream ausgabeStrom;
        ausgabeStrom.str("");
        ausgabeStrom << c;
        cWert = ausgabeStrom.str();


        cout << "Aufgabe " << i+1 << ": " << a << " + " << b << " = ";
        getline(cin, wert);

        if (eingabeZahl(wert) == false)
        {

        }
        else if(eingabeZahl(wert) == true && wert == cWert)
        {
            zaehler++;
        }
        }




    cout << "Richtig: " << zaehler << " von 5" << endl;
}
