#include <iostream>
using namespace std;

bool primzahl(int para) {                               // Funktion, um zu überprüfen, ob eine Zahl eine Primzahl ist
    bool check;
    check = true;
    for (int i = 2; i < para; i++) {                    // Schleife von 2 bis para - 1, um zu prüfen, ob para durch irgendeine andere Zahl teilbar ist
        if(para % i == 0) {
            check = false;                              // Wenn para durch i teilbar ist, ist es keine Primzahl
            break;                                      // Breche die Schleife ab, da keine weitere Überprüfung erforderlich ist
        }
    }
    return (check);                                     // Rückgabe des Ergebnisses, ob para eine Primzahl ist oder nicht
}

int main()
{
    int n;
    cout << "Gebe Sie bitte das Maximum von Zahlen ein, welches berechnet werden soll:" << endl;
    cin >> n;
    cout << endl;
    for(int i = 0; i <= n; i++) {
        if(i == 0 || i == 1) {
            cout << i << " Keine Primzahl" << endl;
        }
        else {
            if(primzahl(i) == true) {
                cout << i << " Primzahl" << endl;
            }
            else {
                cout << i << " keine Primzahl" << endl;
            }
        }
    }
    return 0; // Beendet das Programm
}


// Eine Primzahl ist eine Zahl, die nur durch 1 und sich selbst ohne Rest teilbar ist.

// Wenn Sie eine Zahl haben und überprüfen möchten, ob sie eine Primzahl ist, versuchen Sie,
// diese Zahl durch alle Zahlen zu teilen, die größer als 1 und kleiner als die Zahl selbst sind.

// Wenn Sie eine Zahl finden, durch die die gegebene Zahl ohne Rest teilbar ist, dann ist die gegebene Zahl keine Primzahl.
// 2 3 5 7 11 13 17 19 23 29 31 37 41 43
