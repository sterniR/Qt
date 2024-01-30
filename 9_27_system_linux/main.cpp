#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
    std::string kommando = "ls -l";
    std::system(kommando.c_str());
    kommando.at(6) = 'a';
    std::system(kommando.c_str());
}
