#include <string>
#include <iostream>

void ausnahmeBehandeln() {
    try {
        throw;
    } catch (std::exception& e) {
        std::cout << "Fehler: " << e.what() << '\n';
    }
}

int main()
{
    int position;
    bool fehler;
    std::string s {"Hello World"};

    do
    {
        fehler = true;
        try {
            std::cout << "Position: ";
            std::cin >> position;
            s.at(position) = 'X';
            fehler = false;
        } catch (std::exception& ABC) {
            ausnahmeBehandeln();
        }
    }
    while(fehler);
    std::cout << s << '\n';
}
