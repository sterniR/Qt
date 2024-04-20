#include <iostream>
#include <string>

int main()
{
    std::string s{"Hallo Welt"};
    bool fehler;
    int position;

    do {
        fehler = true;

        try {
            std::cout << "Position: ";
            std::cin >> position;
            s.at(position) = 'X';
            fehler = false;
        }
        catch (std::exception& e) {
            std::cout << "Fehler: " << e.what() << '\n';
        }
    }
    while(fehler);

    std::cout << s << '\n';
}
