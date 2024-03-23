#include <iostream>
#include <string>


int main()
{
    std::string s {"HALLO WELT"};
    std::string::iterator position;

    position = s.begin();
    std::cout << "Beginn:  " << *position << '\n';

    position++;
    std::cout << "++:      " << *position << '\n';

    position = next(position,3);
    std::cout << "next(3): " << *position << '\n';

    position -= 4;
    std::cout << "-= 4:    " << *position << '\n';

    position = s.end();
    position = prev(position,1);
    std::cout << "Ende, dann prev(1): " << *position << '\n';
    for(position=s.begin(); position != s.end(); position++)
        std::cout << *position;
    std::cout << '\n';
}
