#include <iostream>
#include <string>
#include <sstream>
#include <chrono>

void zEingabe()
{
    bool x;
    std::string eingabe, trash;
    std::istringstream eingabeStrom;
    int zahl;
    double abweichung;

    // Hello mee :)
    do
    {
        std::cout << "Bitte Zeit in Sekunden eingeben, zwischen 5 und 10: ";
        std::getline(std::cin, eingabe);
        if (eingabe == "")
        {
            std::cout << "Keine Zahl";
            x = false;
        }
        else;
        {
            eingabeStrom.str(eingabe);
            eingabeStrom >> zahl;
            eingabeStrom.clear();
        }
        //std::cout << zahl << std::endl;
        if(zahl < 5 || zahl > 10)
        {
            //std::cout << "Falsch" << std::endl;
        }
        else
        {
            x = true;
            std::cout << "Wie lang sind " << zahl << " Sekunden?" << std::endl;
            std::cout << "Starten Sie mit der <Enter> Taste" << std::endl;
            std::getline(std::cin, trash);


            std::chrono::time_point<std::chrono::system_clock> beginn = std::chrono::system_clock::now();
            std::cout << zahl << " Sekunden vorbei?" << std::endl;
            std::cout << "Dann Beenden Sie die Schätzung mit der Taste <Enter>" << std::endl;
            std::getline(std::cin, trash);
            std::chrono::time_point<std::chrono::system_clock> ende = std::chrono::system_clock::now();
            std::chrono::duration<double> dauer = ende - beginn;

            std::cout << "Das waren " << dauer.count() << " Sekunden" << std::endl;
            if(zahl < dauer.count())
            {
                abweichung = (dauer.count()-zahl)/zahl*100;
            }
            else
            {
                abweichung = (zahl-dauer.count())/zahl*100;
            }
            std::cout << "Eine Abweichung von " << abweichung << " %" << std::endl;

        }
    }
    while(x == false);
}

int main()
{
    zEingabe();
}
