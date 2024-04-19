#include <string>
#include <iostream>
using namespace std;

string addieren(string a, string b)
{
    return a + b;
}
string summieren(string a, string b)
{
    return addieren(a,b);
}

namespace abstand
{
string addieren(string a, string b)
{
    return a + " " + b;
}
string summieren(string a, string b)
{
    return addieren(a,b);
}
}
int main()
{
    string s1{"Hallo"}, s2{"Welt"};
    std::cout << summieren(s1, s2) << '\n';
    std::cout << abstand::summieren(s1,s2) << '\n';
}
