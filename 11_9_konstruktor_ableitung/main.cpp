#include <iostream>
#include <string>

class figur
{
private:
    double x, y;
    std::string farbe;
public:
    figur();
    figur(const double&, const double&, const std::string&);
    void ausgeben();
    ~figur();
};

figur::figur()
{
    std::cout << "figur-Konstruktor ohne Parameter" << '\n';
}

figur::figur(const double& xPos, const double& yPos, const std::string& f)
{
    std::cout << "figur-Konstruktor mit Parameter" << '\n';
    x = xPos;
    y = yPos;
    farbe = f;
}

void figur::ausgeben()
{
    std::cout << "Figur: " << x << " / " << y << " " << farbe;
}

figur::~figur()
{
    std::cout << "figur-Destruktor" << '\n' << '\n';
}

//Test BranchTestingGit 12:30 3/1/2024


