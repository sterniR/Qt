#include <iostream>
#include <string>
#include <cmath>

class figur
{
private:
    double x, y;
    std::string farbe;
public:
    void werteZuweisen(const double&, const double&, const std::string&);
    void verschieben(const double&, const double&);
    void faerben(const std::string&);
    void ausgeben();
};

void figur::werteZuweisen(const double& xPos, const double& yPos, const std::string& f)
{
    x = xPos;
    y = yPos;
    farbe = f;
}

void figur::verschieben(const double& xDelta, const double& yDelta)
{
    x += xDelta;
    y += yDelta;
}

void figur::faerben(const std::string& f)
{
    farbe = f;
}

void figur::ausgeben()
{
    std::cout << "Figur: " << x << " / " << y << " " << farbe;
}

class rechteck:public figur
{
private:
    double hoehe, breite;
private:
    void werteZuweisen(const double&, const double&, const std::string&, const double&, const double&);
    void skalieren(const double&, const double&);
    double flaeche();
    void ausgeben();
};

void rechteck::werteZuweisen(const double& xPos, const double& yPos, const std::string& f, const double& h, const double& b)
{
    figur::werteZuweisen(xPos, yPos, f);
    hoehe = h;
    breite = b;
}

void rechteck::skalieren(const double& hoeheFaktor, const double& breiteFaktor)
{
    hoehe *= hoeheFaktor;
    breite *= breiteFaktor;
}

double rechteck::flaeche()
{
    return hoehe * breite;
}

void rechteck::ausgeben()
{
    figur::ausgeben();
    std::cout << " Rechteck: " << hoehe << " / " << breite << '\n';
}
