#include <iostream>
#include <vector>
using namespace std;

class bruch
{
   private:
      int z, n;
   public:
      bruch();
      bruch(const int&);
      bruch(const int&, const int&);
      bruch operator * (const bruch&);
      bruch operator / (const bruch&);
      bruch operator + (const bruch&);
      bruch operator - (const bruch&);
      bool operator > (const bruch&);
      bool operator < (const bruch&);
      bool operator == (bruch&);
      void kuerzen();
      void eingabe();
      friend ostream& operator << (ostream&, bruch&);
};

bruch::bruch()
{
   z = 1;
   n = 1;
}

bruch::bruch(const int& wert)
{
   z = wert;
   n = 1;
}

bruch::bruch(const int& zaehler, const int& nenner)
{
   z = zaehler;
   n = nenner;
}

bruch bruch::operator * (const bruch& andererBruch)
{
   bruch b;
   b.z = z * andererBruch.z;
   b.n = n * andererBruch.n;
   return b;
}

bruch bruch::operator / (const bruch& andererBruch)
{
   return bruch(z * andererBruch.n, n * andererBruch.z);
}

bruch bruch::operator + (const bruch& andererBruch)
{
   return bruch(z * andererBruch.n + n * andererBruch.z, n * andererBruch.n);
}

bruch bruch::operator - (const bruch& andererBruch)
{
   return bruch(z * andererBruch.n - n * andererBruch.z, n * andererBruch.n);
}

bool bruch::operator > (const bruch& b)
{
   return 1.0 * z / n > 1.0 * b.z / b.n;
}

bool bruch::operator < (const bruch& b)
{
   return 1.0 * z / n < 1.0 * b.z / b.n;
}

bool bruch::operator == (bruch& b)
{
   this->kuerzen();
   b.kuerzen();
   return z == b.z && n == b.n;
}

void bruch::kuerzen()
{
   vector<int> prim{2, 3, 5, 7};
   for(int i=0; i<prim.size(); i++)
      while(z % prim.at(i) == 0 && n % prim.at(i) == 0)
      {
         z /= prim.at(i);
         n /= prim.at(i);
      }
      
   if(n < 0)
   {
      z = -z;
      n = -n;
   }
}

void bruch::eingabe()
{
   cout << "Eingabe Zaehler: ";
   cin >> z;
   cout << "Eingabe Nenner: ";
   cin >> n;
}

ostream& operator << (ostream& om, bruch& b)
{
   b.kuerzen();
   om << b.z << "/" << b.n;
   return om;
}

int main()
{
   bruch b1;                    cout << "b1:  " << b1 << endl;
   bruch b2(7);                 cout << "b2:  " << b2 << endl;
   bruch b3(6, 5);              cout << "b3:  " << b3 << endl;
   bruch b4(2, 10);             cout << "b4:  " << b4 << endl;
   bruch b5 = b3 * b4;          cout << "b5:  " << b5 << endl;
   bruch b6 = b3 / b4;          cout << "b6:  " << b6 << endl;
   bruch b7 = b3 + b4;          cout << "b7:  " << b7 << endl;
   bruch b8 = b3 - b4;          cout << "b8:  " << b8 << endl;
   bruch b9(3, 2);              cout << "b9:  " << b9 << endl;
   bruch b10 = b3 + b4 * b9;    cout << "b10: " << b10 << endl;
   bruch b11 = (b3 + b4) * b9;  cout << "b11: " << b11 << endl;

   bruch b12(60, 50);           cout << "b12: " << b12 << endl;
   if(b3 > b4)                  cout << "b3 > b4" << endl;
   if(b4 < b3)                  cout << "b4 < b3" << endl;
   if(b3 == b12)                cout << "b3 == b12" << endl;

   bruch b13;
   b13.eingabe();               cout << "b13: " << b13 << endl;
}

