#include <iostream>
#include <string>


template <typename T1>
class meineKlasse {
private:
    T1 wert;
public:
    meineKlasse(const T1&);
    void verdoppeln();
    void ausgeben();
};

template <typename T2>
meineKlasse<T2>::meineKlasse(const T2& neuerWert)
{
    wert = neuerWert;
}

template <typename T3>
void meineKlasse<T3>::verdoppeln()
{
    wert = wert + wert;
}

template <typename T4>
void meineKlasse<T4>::ausgeben()
{
    std::cout << wert << '\n';
}

int main()
{
    meineKlasse<int> x{5};
    x.verdoppeln();
    x.ausgeben();

    meineKlasse<std::string> s{"Hallow"};
    s.verdoppeln();
    s.ausgeben();
}
