#include <map>
#include <iostream>
#include <string>
using namespace std;
void ausgeben(std::map<int, std::string>& x)
{
    for(auto &i : x)
        std::cout << i.first << "/" << i.second << "    ";
    std::cout << '\n';
}

int main()
{
    std::map<int, std::string> m;

    m.insert(std::pair<int, std::string>(30,"Bremen"));
    m.insert(std::pair<int, std::string>(10,"Berlin"));
    m.insert(std::pair<int, std::string>(10,"Potsdam"));
    std::cout << "insert():    ";
    ausgeben(m);

    m[60] = "Frankfurt";
    m[30] = "Hannover";
    m[20] = "Hamburg";
    std::cout << "[]           ";
    ausgeben(m);

    std::map<int, std::string>::iterator pos;
    if((pos = m.find(30)) != m.end())
        std::cout << "find():      30/" << pos->second << '\n';
    if(m.contains(30))
        std::cout << "contains()   30/" << pos->second << '\n';

    cout << "count():     " << m.count(30) << endl;

    m.erase(30);
    cout << "erase():     ";
    ausgeben(m);

    map<int,string> mi{{35,"Italien"},{65,"Polen"},{45,"Schweden"}};
    map<int,string> mk{{85,"Belgien"},{35,"Slowenien"}};
    mi.merge(mk);

    cout << "merge():     ";
    ausgeben(mi);

    cout << "merge():     ";
    ausgeben(mk);

    map md{pair{25, "Spanien"}, {15, "Irland"}, {25, "Schweiz"}};
    cout << "Anzahl:      ";
    cout << md.size() << endl;
}
