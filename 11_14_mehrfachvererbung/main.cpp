#include <iostream>
#include <string>

using namespace std;

class figur
{
private:
    double x, y;
    std::string farbe;
public:
    figur(const double&, const double&, const std::string&);
    void verschieben(const double&, const double&);
    void faerben(const std::string&);
    virtual double flaeche(){return 0.0;};
    virtual void ausgeben();
};

figur::figur(const double& xPos, const double& yPos, const std::string& f)
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

void figur::faerben(const std::string& farbeNeu)
{
    farbe = farbeNeu;
}

void figur::ausgeben()
{
    std::cout << "Figur: " << x << " / " << y << " " << farbe << '\n';
}

class rechteck:public figur
{
private:
    double hoehe, breite;
public:
    rechteck(const double&, const double&, const std::string&, const double&, const double&);
    void skalieren(const double&, const double&);
    double flaeche();
    void ausgeben();
};

rechteck::rechteck(const double& xPos, const double& yPos, const std::string& f,
                   const double& h, const double& b):figur(xPos, yPos, f)
{
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

class textzeile
{
private:
    std::string inhalt;
    std::string art;
    std::string farbe;
    double groesse;
public:
    textzeile(const std::string&, const std::string&, const std::string&, const double&);
    void ausgeben();
};

textzeile::textzeile(const std::string& i, const std::string& a,
                     const std::string& f, const double& g)
{
    inhalt = i;
    art = a;
    farbe = f;
    groesse = g;
}

void textzeile::ausgeben()
{
    std::cout << "Textzeile: " << inhalt << " " << art
              << " " << farbe << " " << groesse << std::endl;
}

class rechteckTextzeile:public rechteck, public textzeile
{
private:
    std::string ausrichtung;
public:
    rechteckTextzeile(const double&, const double&, const std::string&,
                      const double&, const double&,
                      const std::string&, const std::string&, const std::string&, const double&,
                      const std::string&);
    void ausgeben();
};

rechteckTextzeile::rechteckTextzeile(
    const double& xPos, const double& yPos, const string& fr,
    const double& h, const double& b,
    const string& tx, const string& art,
    const string& ft, const double& groesse,
    const string& aus):
    rechteck{xPos, yPos, fr, h, b},
    textzeile{tx, art, ft, groesse}
{
    ausrichtung = aus;
}

void rechteckTextzeile::ausgeben()
{
    rechteck::ausgeben();
    textzeile::ausgeben();
    std::cout << "Rechteck-Textzeile: " << ausrichtung << '\n';
}

int main()
{
    textzeile ta{"Guten Morgen", "Tahoma", "Schwarz", 12};
    ta.ausgeben();
    std::cout << '\n';

    rechteckTextzeile rta{5.2, 1.8, "Blau", 1.2, 3.5, "Hallo Welt", "Arial", "Rot", 8.5, "Zentriert"};
    rta.ausgeben();
}
