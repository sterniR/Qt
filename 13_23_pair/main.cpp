#include <iostream>
#include <string>
#include <utility>

int main()
{
    std::pair<int,std::string> pa;
    pa = std::pair<int,std::string>(10, "Berlin");
    std::cout << std::get<0>(pa) << "/" << std::get<1>(pa) << '\n';

    std::pair<int, std::string> pb;
    pb = std::make_pair(20, "Hamburg");
    pb.swap(pa);
    std::cout << pa.first << "/" << pa.second << '\n';

    std::pair<int,std::string> pc;
    pc = pb;
    std::cout << pc.first << "/" << pc.second << '\n';

    std::pair<int,std::string> pd;
    pd.first = 30;
    pd.second = "Dortmund";
    std::cout << pd.first << "/" << pd.second << '\n';

    std::pair pe{40, "Stuttgart"};
    std::cout << pe.first << "/" << pe.second << '\n';

}
