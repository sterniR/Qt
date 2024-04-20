#include <string>
#include <iostream>


int main()
{
    std::string s{"Hallo Welt"};
    bool fehler;
    int position;

    do
    {
        fehler = true;
        try {
            std::cout << "Position: ";
            std::cin >> position;

            if(position < 0)
                throw 1;
            if(position >= 100)
                throw 2;
            if(position >= 10)
                throw 3;
            s.at(position) = 'X';
            fehler = false;
        } catch (int i) {
            if(i == 1)
                std::cout << "Fehler: Position ist negativ" << '\n';
            else if(i == 2)
                std::cout << "Fehler: Position ist ueber 100" << '\n';
            else if(i == 3)
                std::cout << "Fehler: Position ist grosser als String" << '\n';
        }
        catch(std::exception& e) {
            std::cout << "Fehler: " << e.what() << '\n';
        }
    }
    while(fehler);
    std::cout << s << '\n';
}
