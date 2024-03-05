#include <iostream>
#include <string>

using namespace std;

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

class rechteck:public figur
{
private:
    double hoehe, breite;
public:
    rechteck();
    rechteck(const double&, const double&, const std::string&, const double&, const double&);
    void ausgeben();
    ~rechteck();
};

rechteck::rechteck()
{
    std::cout << "rechteck-Konstruktor ohne Parameter" << std::endl;
}

rechteck::rechteck(const double& xPos, const double& yPos, const std::string& f, const double& h, const double& b):figur{xPos, yPos, f}
{
    std::cout << "rechteck-Konstruktor mit Parametern" << std::endl;
    hoehe = h;
    breite = b;
}

void rechteck::ausgeben()
{
    figur::ausgeben();
    cout << " Rechteck: " << hoehe << " / " << breite << endl;
}

rechteck::~rechteck()
{
    std::cout << "rechteck-Destruktor" << std::endl;
}

int main()
{
    rechteck ra{7.4, 2.3, "Blau", 4.0, 2.6};
    ra.ausgeben();
    std::cout << '\n';

    ra.ausgeben();
    cout << endl;
    rechteck rb;
    cout << endl;
}

