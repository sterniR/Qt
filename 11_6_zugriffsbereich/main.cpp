#include <iostream>

class figur
{
private:
    double x, y;
protected:
    std::string farbe;
public:
    void werteZuweisen(const double&, const double&, const std::string&);
    void ausgeben();
};

class rechteck:public figur
{
private:
    double hoehe, breite;
public:
    void werteZuweisen(const double&, const double&, const std::string&, const double&, const double&);
    void ausgeben();
    void ausgebenFarbe();
};

void figur::werteZuweisen(const double& xPos, const double& yPos, const std::string& f)
{
    x = xPos;
    y = yPos;
    farbe = f;
}

void figur::ausgeben()
{
    std::cout << "Figur: " << x << " / " << y << " " << farbe;
}

void rechteck::werteZuweisen(const double& xPos, const double& yPos, const std::string& f, const double& h, const double& b)
{
    figur::werteZuweisen(xPos, yPos, f);
    hoehe = h;
    breite = b;
}

void rechteck::ausgeben()
{
    figur::ausgeben();
    std::cout << " Rechteck: " << hoehe << " / " << breite << '\n';
}

void rechteck::ausgebenFarbe()
{
    std::cout << "Farbe: " << farbe << '\n';
}

int main()
{
    rechteck ra;
    ra.werteZuweisen(7.4,2.3,"Blau",4.0,2.6);
    ra.ausgeben();
    ra.ausgebenFarbe();
    // std::cout << ra.farbe << std::endl;
}
