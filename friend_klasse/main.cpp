#include <string>
#include <iostream>
using namespace std;

class postenTyp {
    friend class postenAktion;

private:
    int anzahl;
    double preis;
    std::string bezeichnung;
public:
    postenTyp(int, double, std::string);
    void ausgeben();
};

class postenAktion {
public:
    static void
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
